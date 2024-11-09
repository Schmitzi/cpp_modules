#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed() : num(0) { 
    std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& f) { 
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

// Copy Assignment Constructor
Fixed& Fixed::operator=(const Fixed& F) {
    if (this != &F) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->num = F.getRawBits();
    }
    return *this;
}

// Int Constructor
Fixed::Fixed(const int num) { 
    std::cout << "Int Constructor called" << std::endl;
    this->num = num << bit;
}

//Float Constructor
Fixed::Fixed(const float num) { 
    std::cout << "Float Constructor called" << std::endl;
	this->num = roundf(num * (1 << bit));
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// << Operator Overload
std::ostream& operator<<( std::ostream& output, const Fixed& D ) { 
	return (output << D.toFloat());
}

int	Fixed::getRawBits( void ) const {
    return this->num;
}

void	Fixed::setRawBits( int const raw ) {
	this->num = raw;
}

float   Fixed::toFloat() const {
    return (float)this->num / (1 << bit);
}

int Fixed::toInt() const {
    return this->num >> bit;
}
