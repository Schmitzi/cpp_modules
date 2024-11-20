#include "Cat.hpp"

Cat::Cat() {
	setType("Cat");
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const std::string type) {
	setType(type);
	std::cout << "Cat " << getType() << " constructed" << std::endl;
}

Cat& Cat::operator= (const Cat& C) {
    if (this != &C) { 
        setType(C.getType());
    }
    return *this;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "*Meow*" << std::endl;
}
