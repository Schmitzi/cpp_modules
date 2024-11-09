#pragma once

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		// Constructors
		HumanB(std::string name);
		~HumanB();

		//Member Functions
		void attack();
		void setWeapon(Weapon &weapon);
};
