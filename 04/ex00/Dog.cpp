#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const std::string type) {
	setType(type);
	std::cout << "Dog " << getType() << " constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& D) {
    if (this != &D) { 
        setType(D.getType());
    }
    return *this;
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "*Woof*" << std::endl;
}
