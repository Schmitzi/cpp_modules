#include "Span.hpp"

Span::Span() {
	_maxSize = 0;
}

Span::Span(unsigned int n) {
	_store.reserve(n);
	_maxSize = n;
}

Span& Span::operator=(const Span& S) {
    if (this != &S) {
        _store = S._store;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(unsigned int num) {
    if (_store.size() >= _maxSize) {
        throw NoSpaceException();
    }
    _store.push_back(num);
}

size_t Span::shortestSpan() {
    if (_store.size() < 2) {
        throw NoSpanException();
    }

    std::sort(_store.begin(), _store.end());
    size_t minSpan = std::numeric_limits<size_t>::max();
    
    for (size_t i = 1; i < _store.size(); i++) {
        size_t currentSpan = _store[i] - _store[i-1];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

size_t Span::longestSpan() {
    if (_store.size() < 2) {
        throw NoSpanException();
    }
    std::sort(_store.begin(), _store.end());
    return _store.back() - _store.front(); 
}

void Span::fillSpan() {
    srand(time(0));
    
    for (size_t i = 0; i < _maxSize; i++) {
        addNumber(rand());
    }
}
