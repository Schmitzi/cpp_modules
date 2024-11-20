#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal() : _type("WrongAAnimal") {
    std::cout << "WrongAAnimal constructed" << std::endl;
}

WrongAAnimal::WrongAAnimal(const std::string type) : _type(type) {
    std::cout << "WrongAAnimal " << getType() << " constructed" << std::endl;
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal& A) {
    if (this != &A) {
        _type = A._type;
    }
    return *this;
}

WrongAAnimal::~WrongAAnimal() {
    std::cout << "WrongAAnimal destroyed" << std::endl;
}

void WrongAAnimal::makeSound() const {
    std::cout << "*Squawk*" << std::endl;
}

std::string WrongAAnimal::getType() const {
    return _type;
}

void WrongAAnimal::setType(const std::string& type) {
    _type = type;
}

