#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span& operator=(const Span& S);
        ~Span();
        void addNumber(unsigned int n);
        size_t shortestSpan();
        size_t longestSpan();

		void fillSpan();

        class NoSpaceException : public std::exception {
            public:
                const char* what() const throw() {
                    return "No space left in container!";
                }
        };
        class NoSpanException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Too few numbers for span!";
                }
        };
    private:
        std::vector<unsigned int> _store;
		unsigned int _maxSize;
};

#endif
