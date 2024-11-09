#include "Fixed.hpp"

// Defaut Constructor
Fixed::Fixed() {
    this->num = 0;
    std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called" << std::endl;
    this->num = f.getRawBits();
}

// Copy Assignment Constructor
Fixed& Fixed::operator=(const Fixed& f)
{
    if (this != &f) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->num = f.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void Fixed::setRawBits(int const raw) {
    this->num = raw;
}


