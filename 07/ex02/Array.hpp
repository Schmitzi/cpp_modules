#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& A);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int getSize() const;
    private:
        T* _data;
        unsigned int _size;
};

template <typename T>
std::ostream& operator<<(std::ostream& output, const Array<T>& a);

#include "Array.tpp"

#endif