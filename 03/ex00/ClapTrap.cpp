#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name  << " Constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " Constructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& C) {
    if (this != &C) { 
        _name = C._name;
        _hitPoints = C._hitPoints;
        _energyPoints = C._energyPoints;
        _attackDamage = C._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " Destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " does not have enough Energy to attack" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage <<
			" points of damage!" << std::endl;
        _energyPoints -= 1;
    } 
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    _hitPoints = (_hitPoints > static_cast<int>(amount)) ? _hitPoints - amount : 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot repair itself" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " does not have enough Energy to repair" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " regained " << amount << " hit points!" << std::endl;
        _hitPoints += amount;
        _energyPoints -= 1;
    }
}

int ClapTrap::getHitPoints() const {
    return _hitPoints;
}
