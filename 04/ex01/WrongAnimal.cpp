#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
    std::cout << "WrongAnimal " << getType() << " constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& A) {
    if (this != &A) {
        _type = A._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "*Squawk*" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::setType(const std::string& type) {
    _type = type;
}

