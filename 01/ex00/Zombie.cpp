#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << this->name << " constructed" << std::endl;	
}

Zombie::~Zombie( void ){
	std::cout << this->name << " deconstructed" << std::endl;
}

void Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
