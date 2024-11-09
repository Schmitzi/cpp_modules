#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed() : num(0) {
    std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed( const Fixed& f ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

// Int Constructor
Fixed::Fixed( const int num ) {
    std::cout << "Int Constructor called" << std::endl;
    this->num = num << bit;
}

//Float Constructor
Fixed::Fixed( const float num ) { 
    std::cout << "Float Constructor called" << std::endl;
	this->num = roundf(num * (1 << bit));
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& O) {
    if (this != &O) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->num = O.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() { 
    std::cout << "Destructor called" << std::endl;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.num == 0) {
        std::cerr << "Division by zero error" << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->num > other.num;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->num < other.num;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->num >= other.num;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->num <= other.num;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->num == other.num;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->num != other.num;
}

// Pre-increment and pre-decrement operators
Fixed& Fixed::operator++() {
    ++num;
    return *this;
}

Fixed& Fixed::operator--() {
    --num;
    return *this;
}

// Post-increment and post-decrement operators
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

float   Fixed::toFloat() const {
    return (float)this->num / (1 << bit);
}

int Fixed::toInt() const {
    return this->num >> bit;
}

int	Fixed::getRawBits( void ) const {
    return this->num;
}

void	Fixed::setRawBits( int const raw ) {
	this->num = raw;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

// Operator Overloads
std::ostream& operator<<( std::ostream& output, const Fixed& D ) { 
			return (output << D.toFloat());
}