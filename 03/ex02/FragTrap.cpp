#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructed with default values." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "FragTrap " << _name << " constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& F) {
    if (this != &F) { 
        _name = F._name;
        _hitPoints = F._hitPoints;
        _energyPoints = F._energyPoints;
        _attackDamage = F._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " Destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " is dead and cannot attack" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " does not have enough Energy to attack" << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    } 
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap requests a High Five, Don't leave them hanging" << std::endl;
}
