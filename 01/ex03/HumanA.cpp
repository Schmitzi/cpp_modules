#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon): name(name), weapon(weapon) {
	std::cout << name << " spawned with " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->name << " despawned" << std::endl;
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon) {
	this->weapon = weapon;
}
