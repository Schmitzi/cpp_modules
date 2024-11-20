#include "Cat.hpp"

Cat::Cat() {
	setType("Cat");
	_brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) { 
    _brain = new Brain(*other._brain);
    setType(other.getType());
    std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) { 
    if (this != &other) {
        delete _brain; 
        _brain = new Brain(*other._brain);
        setType(other.getType());
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "*Meow*" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    _brain->setType(index, idea);
}

std::string Cat::getIdea(int index) const {
    return _brain->getType(index);
}
