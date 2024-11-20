#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const std::string type) {
    _type = type;
    std::cout << "WrongCat " << getType() << " constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& C) {
    if (this != &C) {
        _type = C._type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "*Rawr*" << std::endl;
}

