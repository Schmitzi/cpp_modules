#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap& operator=(const ScavTrap& S);
		~ScavTrap();
	
		void	attack(const std::string& target);
		void	guardGate();
	};

#endif
