#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	_brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);
    setType(other.getType());
    std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        delete _brain; 
        _brain = new Brain(*other._brain);
        setType(other.getType());
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "*Woof*" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    _brain->setType(index, idea);
}

std::string Dog::getIdea(int index) const {
    return _brain->getType(index);
}
