#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	_type = type;
	std::cout << "AAnimal " << getType() << " constructed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& A) {
    if (this != &A) { 
        _type= A._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed" << std::endl;
}

void AAnimal::makeSound() const{
	std::cout << "*crickets*" << std::endl;
}

std::string AAnimal::getType() const{
	return _type;
}

void AAnimal::setType(const std::string& type) {
    _type = type;
}
