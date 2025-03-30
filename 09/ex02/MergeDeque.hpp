#ifndef MERGEDEQUE_HPP
#define MERGEDEQUE_HPP

#include <bits/types/struct_timeval.h>
#include <iostream>
#include <deque>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

typedef	std::deque<std::deque<int> > Deque;

typedef struct d_elem {
	Deque			_nums;
	size_t			_index;

} d_elem;

typedef	std::deque<d_elem>			Elems_Dq;

class MergeDeque {
	public:
                struct  timeval 	_start;
                struct  timeval 	_end;

                MergeDeque();

                void			solve(char **av);
                void   			finalCheck(std::deque<int> container, size_t size);

                size_t  		getComp();
                void   			setTime(double time);
                double 			getTime();
                std::deque<int>	        getPending();
	private:
                Elems_Dq		_sorted;
                Elems_Dq		_unsorted;
                Deque			_odd;
                std::deque<int>	        _pending;
                Deque			_newPairs;
                std::deque<int>	        _jacobsNums;
                size_t			_currJacob;
                size_t			_prevJacob;
                size_t			_comp;
                double                  _time;

                int			setRawNums(char **av);
                void			createPairs(size_t pairSize);
                void			recurPairs(size_t pairSize);
                void    		swapPairs(Deque&_newPairs);
                void			buildPending(Deque& que);
                void			printDq(const std::deque<int> dq, std::string str);
                void 			printDoubleDq(const Deque dq, std::string str);
                void			jacobSort(size_t pairSize);
                void			sortPairs(size_t pairSize);
                size_t			binSearch(Deque item, size_t high);
                void			stripElems();
                size_t			getJacob(size_t n);
                void			jacobPreCalc();
                void			printElems(Elems_Dq elem, std::string str);
                int     		ft_atoi(const char *nptr);
};

#endif
