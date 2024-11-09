#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL){
	this->name = name;
	std::cout << name << " spawned without a weapon" << std::endl;
}

HumanB::~HumanB() {
	std::cout << name << " despawned" << std::endl;
}

void HumanB::attack() {
    if (weapon) {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
    }
}

void	HumanB::setWeapon(Weapon &weapon) {
	std::cout << "Gave " << this->name << " a " << weapon.getType() << std::endl;
	this->weapon = &weapon;
}
