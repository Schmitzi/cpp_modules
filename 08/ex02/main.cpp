#include "MutantStack.hpp"

int main()
{
	std::cout << "----- MutantStack -----" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "----- Extra -----" << std::endl;

	MutantStack<int> cstack(mstack);
	for (size_t i = 0; i < 3; i++) {
		cstack.pop();
	}

	std::cout << cstack.top() << std::endl;

	cstack.push(5);
	cstack.push(17);

	std::cout << cstack.size() << std::endl;

	cstack.push(42);
	cstack.push(8);
	cstack.push(420);

	MutantStack<int>::iterator c_it = cstack.begin();
	MutantStack<int>::iterator c_ite = cstack.end();

	++c_it;
	--c_it;
	while (c_it != c_ite)
	{
		std::cout << *c_it << std::endl;
		++c_it;
	}
	if (cstack.empty() == 1) {
		std::cout << "Stack is empty" << std::endl;
	} else {
		std::cout << "Stack is not empty" << std::endl;
	}

	std::cout << "Size: " << cstack.size() << std::endl;

	std::cout << "----- List -----" << std::endl;

	std::list<int>	list;
	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator l_it = list.begin();
	std::list<int>::iterator ite_list = list.end();

	++l_it;
	--l_it;
	while (l_it != ite_list)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}
	if (list.empty() == 1) {
		std::cout << "Stack is empty" << std::endl;
	} else {
		std::cout << "Stack is not empty" << std::endl;
	}
	std::cout << "Size: " << list.size() << std::endl;
	std::stack<int, std::list<int> > l(list);	
	return 0;
}