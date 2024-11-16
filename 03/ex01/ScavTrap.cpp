#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructed with default values." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " Constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap S) {
    if (this != &S) {
		std::swap(*this, S);
	}
    return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " Destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is dead and cannot attack" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " does not have enough Energy to attack" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << 
			_attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    } 
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}
