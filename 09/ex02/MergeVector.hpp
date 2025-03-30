#ifndef MERGEVECTOR_HPP
#define MERGEVECTOR_HPP

#include <bits/types/struct_timeval.h>
#include <cstddef>
#include <iostream>
#include <vector>
#include <cmath>

typedef	std::vector<std::vector<int> > Vector;

typedef struct v_elem {
	Vector			_nums; 
	size_t			_index;

} v_elem;

typedef	std::vector<v_elem>			Elems_Vec;


class MergeVector {
	public:
        struct  timeval 	_start;
        struct  timeval 	_end;

		MergeVector();

		void				solve(char **av);
        void    			finalCheck(std::vector<int> container, size_t size);

		size_t  			getComp();
        void    			setTime(double time);
        double  			getTime();
        std::vector<int>	getPending();
	private:
		Elems_Vec			_sorted;
		Elems_Vec			_unsorted;
		Vector				_odd;
		std::vector<int>	_pending;
		Vector				_newPairs;
		std::vector<int>	_jacobsNums;
		size_t				_currJacob;
		size_t				_prevJacob;
		size_t				_comp;
        double              _time;

		int					setRawNums(char **av);
		void				createPairs(size_t pairSize);
		void				recurPairs(size_t pairSize);
		void    			swapPairs(Vector&_newPairs);
		void				buildPending(Vector& que);
		void				printVec(const std::vector<int> vec, std::string str);
		void 				printDoubleVec(const Vector vec, std::string str);
		void				jacobSort(size_t pairSize);
		void				sortPairs(size_t pairSize);
		size_t				binSearch(Vector item, size_t high);
		void				stripElems();
		size_t				getJacob(size_t n);
		void				jacobPreCalc();
		void				printElems(Elems_Vec elem, std::string str);
        int     			ft_atoi(const char *nptr);
};

#endif
