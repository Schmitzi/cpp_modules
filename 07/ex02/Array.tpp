#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {
    //std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
    //std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
    //std::cout << "Copy constructor called" << std::endl;
    for (unsigned int i = 0; i < _size; ++i)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& A) {
    if (this != &A) {
        //std::cout << "Copy assignment operator called" << std::endl;
        delete[] _data;
        _size = A._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = A._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    //std::cout << "Destructor called" << std::endl;
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
    return _size;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, const Array<T>& a) {
    output << "[";
    for (unsigned int i = 0; i < a.getSize(); ++i) {
        output << a[i];
        if (i != a.getSize() - 1)
            output << ", ";
    }
    output << "]";
    return output;
}
