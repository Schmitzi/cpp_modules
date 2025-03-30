#include "MergeVector.hpp"

MergeVector::MergeVector() : _currJacob(0), _prevJacob(0), _comp(0), _time(0) {

}

void	MergeVector::solve(char **av) {
	setRawNums(av);
	jacobPreCalc();
	recurPairs(1);
}

int MergeVector::setRawNums(char **av) {
    for (size_t i = 1; av[i]; i++) {
        if (static_cast<std::string>(av[i]).length() > 10 || ft_atoi(av[i]) > 2147483647) {
            return 1;
        }
        if ((ft_atoi(av[i]) < 0)) {
            return 1;
        }
        _pending.push_back(ft_atoi(av[i]));
    }
    return 0;
}

void	MergeVector::createPairs(size_t pairSize) {
    std::vector<int> temp;

	while (_pending.size() >= pairSize) {
		for (size_t i = 0; i < pairSize; i++) {
			if (!_pending.empty()){
				temp.push_back(_pending.front());
                _pending.erase(_pending.begin());
			}
		}
		if (!temp.empty()) {
			_newPairs.push_back(temp);
		}
		temp.clear();
	}
}


void    MergeVector::swapPairs(Vector &_newPairs) {
    for (size_t i = 0; i < _newPairs.size() - 1; i += 2) {
        _comp++;
        if (_newPairs[i].front() < _newPairs[i + 1].front()) {
            std::swap(_newPairs[i], _newPairs[i + 1]);
        }
    }
}

void MergeVector::buildPending(Vector& que) {
    std::vector<int> temp;
    std::vector<int> old = _pending;
    
    for (size_t i = 0; i < que.size(); i++) {
        for (size_t j = 0; j < que[i].size(); j++) {
            temp.push_back(que[i][j]);
        }
    }
  
    _pending = temp;
    while (!old.empty()) {
        _pending.push_back(old.front());
        old.erase(old.begin());
    }
    que.clear();
}

void MergeVector::recurPairs(size_t pairSize) {
    std::vector<int> temp;

    if (_pending.size() < pairSize * 2) {
        return ;
    }

    createPairs(pairSize);

    swapPairs(_newPairs);
    
    buildPending(_newPairs);
    recurPairs(pairSize * 2);
	jacobSort(pairSize);
}

void MergeVector::sortPairs(size_t pairSize) {
    for (size_t i = 0; i < _newPairs.size(); i++) {

        if (i + 1 >= _newPairs.size() || _newPairs[i].size() < pairSize || _newPairs[i + 1].size() < pairSize) {
            _odd.push_back(_newPairs[i]);
            continue;
        }
        
        if (_newPairs[i].front() > _newPairs[i + 1].front()) {

            v_elem sortedElem;
            sortedElem._nums.push_back(_newPairs[i]);
            sortedElem._index = _sorted.size();
            _sorted.push_back(sortedElem);
            
            v_elem unsortedElem;
            unsortedElem._nums.push_back(_newPairs[i + 1]);
            unsortedElem._index = _unsorted.size();
            _unsorted.push_back(unsortedElem);
        } else {
            v_elem sortedElem;
            sortedElem._nums.push_back(_newPairs[i + 1]);
            sortedElem._index = _sorted.size();
            _sorted.push_back(sortedElem);
            
            v_elem unsortedElem;
            unsortedElem._nums.push_back(_newPairs[i]);
            unsortedElem._index = _unsorted.size();
            _unsorted.push_back(unsortedElem);
        }
        
        i++;
    }
	_newPairs.clear();
}

void	MergeVector::jacobSort(size_t pairSize) {
	_sorted.clear();
	_unsorted.clear();

	createPairs(pairSize);
	sortPairs(pairSize);
	_newPairs.clear();

	_sorted.insert(_sorted.begin(), _unsorted[0]);
	
	for (size_t i = 0; i < _jacobsNums.size() - 1 && i < _unsorted.size(); i++) {
		_currJacob = _jacobsNums[i];
		if (_currJacob >= _unsorted.size()) {
			_currJacob = _unsorted.size() - 1;
		}
        if (i == 0) {
            _prevJacob = 0;
        } else {
		    _prevJacob = _jacobsNums[i - 1];
        }

		while (_currJacob > _prevJacob) {
			size_t high;
			for (size_t j = 0; j < _sorted.size(); j++) {
				if (_sorted[j]._index == _unsorted[_currJacob]._index) {
					high = j;
					break;
				}
			}
			if (_currJacob < _unsorted.size()) {
				size_t pos = binSearch(_unsorted[_currJacob]._nums, high);
				_sorted.insert(_sorted.begin() + pos, _unsorted[_currJacob]);
			}
			_currJacob--;
		}
	}

	if (pairSize == 1) {
	    Vector extra;
    
        for (size_t i = 0; i < _odd.size(); i++) {
            for (size_t j = 0; j < _odd[i].size(); j++) {
                std::vector<int> temp;
                temp.push_back(_odd[i][j]);
                extra.push_back(temp);
            }
        }

        for (size_t i = 0; i < extra.size(); i++) {
			v_elem temp;
			temp._nums.push_back(extra[i]);
			temp._index = 0;
            size_t pos = binSearch(temp._nums, _sorted.size());
            _sorted.insert(_sorted.begin() + pos, temp);
        }
		_odd.clear();
    }
	stripElems();
}

void MergeVector::stripElems() {
    std::vector<int> temp;
    std::vector<int> old = _pending;
    _pending.clear(); 
    

    for (size_t i = 0; i < _sorted.size(); i++) {
        for (size_t j = 0; j < _sorted[i]._nums.size(); j++) {
            for (size_t k = 0; k < _sorted[i]._nums[j].size(); k++) {
                temp.push_back(_sorted[i]._nums[j][k]);
            }
        }
    }
        
   
    for (size_t i = 0; i < temp.size(); i++) {
        _pending.push_back(temp[i]);
    }
    
    
    while (!old.empty()) {
        _pending.push_back(old.front());
        old.erase(old.begin());
    }
}

size_t MergeVector::binSearch(Vector item, size_t high) {
    size_t low = 0;
    int searchValue = item.front().front(); 
    
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        _comp++; 
        if (searchValue < _sorted[mid]._nums.front().front()) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

size_t MergeVector::getJacob(size_t n) {
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return getJacob(n - 1) + 2 * getJacob(n - 2);
}

void MergeVector::jacobPreCalc() {
       _jacobsNums.clear();
    
    size_t curr = 1;
    size_t idx = 1;
        
    while (curr <= _pending.size() / 2) {
        curr = getJacob(++idx);
        _jacobsNums.push_back(curr);
    }
}

void MergeVector::printVec(const std::vector<int> dq, std::string str) {
	std::vector<int> temp = dq;

    if (str != "NULL") {
        std::cout << str << "\t";
    }
    if (dq.empty()) {
        std::cout << "(empty)\n";
        return;
    }
    for (size_t i = 0; i < dq.size(); i++) {
        std::cout << temp[i];
        if (i != temp.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

void MergeVector::printDoubleVec(const Vector dq, std::string str) {
	std::cout << str << "\t";
    for (size_t i = 0; i < dq.size(); i++) {
		std::cout << "(";
		for (size_t j = 0; j < dq[i].size(); j++) {
        	std::cout << dq[i][j];
			if (j != dq[i].size() - 1) {
				std::cout << ", ";
			}
        }
		std::cout << ")";
    }
    std::cout << "\n";
}

void MergeVector::printElems(Elems_Vec elem, std::string str) {
    if (str != "NULL") {
        std::cout << str << "\t";
    }
    
    if (elem.empty()) {
        std::cout << "(empty)\n";
        return;
    }
    
    for (size_t i = 0; i < elem.size(); i++) {
        
        for (size_t j = 0; j < elem[i]._nums.size(); j++) {
            std::cout << "[";
            
            for (size_t k = 0; k < elem[i]._nums[j].size(); k++) {
                std::cout << elem[i]._nums[j][k];
                
                if (k != elem[i]._nums[j].size() - 1) {
                    std::cout << ", ";
                }
            }
            
            std::cout << "]";
            
            if (j != elem[i]._nums.size() - 1) {
                std::cout << " | ";
            }
        }
    }
    
    std::cout << std::endl;
}

int	MergeVector::ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	sign = 0;
	num = 0;
	i = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\r' || *nptr == '\f')
		nptr++;
	{
		if (*nptr == '-')
			sign = 1;
		if (*nptr == '-' || *nptr == '+')
			nptr++;
		while (nptr[i] >= 48 && nptr[i] <= 57)
		{
			num = (nptr[i] - 48) + (10 * num);
			i++;
		}
		if (sign == 1)
			num = num * -1;
	}
	return (num);
}

void    MergeVector::finalCheck(std::vector<int> container, size_t size) {
    for (size_t i = 1; i < container.size(); i++) {
        if (container[i] < container[i - 1]) {
            std::cerr << "Error: Not sorted" << std::endl;
			return;
        }
    }
    if (container.size() != size) {
        std::cerr << "Error: Wrong amount of numbers" << std::endl;
        return;
    }
}

size_t  MergeVector::getComp() {
    return _comp;
}


void    MergeVector::setTime(double time) {
    _time = time;
}

std::vector<int>    MergeVector::getPending() {
    return _pending;
}

double  MergeVector::getTime() {
    return _time;
}
