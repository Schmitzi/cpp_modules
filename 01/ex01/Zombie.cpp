#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie constructed" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " deconstructed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name) {
	this->name = name;
}
