#ifndef	PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include "MergeVector.hpp"
#include "MergeDeque.hpp"

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        int     firstPrint(char **av);
		void 	secondPrint(const std::deque<int>& container); 
		void 	secondPrint(const std::vector<int>& container); 
		void    thirdPrint(MergeDeque dq);
		void    forthPrint(MergeVector vec);
		int		ft_atoi(const char *nptr);
    private:
        
};

#endif
