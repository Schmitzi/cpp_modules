#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Value not found!";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif
