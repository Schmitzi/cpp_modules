#include "PmergeMe.hpp"

double timeSort(struct timeval &start, struct timeval &end) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    return elapsed;
}

int main(int ac, char **av) {
    if (ac < 1) {
		std::cerr << "Error:......how?\n"; 
		return 1;
	}

    PmergeMe    merge;

	MergeDeque dq;
	MergeVector vec;

	if (merge.firstPrint(av) == 1) {
		return 1;
	}
    
	// Measure time for deque
	gettimeofday(&dq._start, 0);
	dq.solve(av);
	gettimeofday(&dq._end, 0);
	dq.setTime(timeSort(dq._start, dq._end));

	// Measure time for deque
	gettimeofday(&vec._start, 0);
	vec.solve(av);
	gettimeofday(&vec._end, 0);
	vec.setTime(timeSort(vec._start, vec._end));

    // Print Second Message
	merge.secondPrint(dq.getPending());
	//merge.secondPrint(vec.getPending());

	// Print Last messages with times
	merge.thirdPrint(dq);
	merge.forthPrint(vec);

	dq.finalCheck(dq.getPending(), ac - 1);
	vec.finalCheck(vec.getPending(), ac - 1);

	//std::cout << "Deque Comp: " << dq.getComp() << "\n";
	//std::cout << "Vector Comp: " << vec.getComp() << "\n";
}
