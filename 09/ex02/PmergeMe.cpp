#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {
	
}

int    PmergeMe::firstPrint(char **av) {
    for (size_t i = 1; av[i]; i++) {
        if (ft_atoi(av[i]) < 0) {
            std::cout << "Error\n";
            return 1;
        }
    }
    std::cout << "Before:\t";
    if (!av[1]) {
        std::cout << "(empty)\n";
        return 0;
    }

    for (size_t i = 1; av[i]; i++) {
        std::cout << av[i];
        if (av[i + 1]) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

void PmergeMe::secondPrint(const std::vector<int>& container) {
    std::cout << "After:\t";
    if (container.empty()) {
        std::cout << "(empty)\n";
        return ;
    }
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i + 1 != container.size()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::secondPrint(const std::deque<int>& container) {
    std::cout << "After:\t";
    if (container.empty()) {
        std::cout << "(empty)\n";
        return ;
    }
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i];
        if (i + 1 != container.size()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::thirdPrint(MergeDeque dq) {
    std::cout << "Time to process range of " << dq.getPending().size() << " with std::deque:\t" << std::fixed << std::setprecision(6) << dq.getTime() << std::endl;
}

void    PmergeMe::forthPrint(MergeVector vec) {
    std::cout << "Time to process range of " << vec.getPending().size() << " with std::vector:\t" << std::fixed << std::setprecision(6) << vec.getTime() << std::endl;
}

int	PmergeMe::ft_atoi(const char *nptr)
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
