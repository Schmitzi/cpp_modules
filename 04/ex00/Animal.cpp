#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const std::string type) {
	_type = type;
	std::cout << "Animal " << _type << " constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& A) {
    if (this != &A) { 
        _type = A._type;
    }
    return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "*crickets*" << std::endl;
}

std::string Animal::getType() const{
	return _type;
}

void Animal::setType(const std::string& type) {
    _type = type;
}
