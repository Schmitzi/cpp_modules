#pragma once

#include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie(std::string);
		~Zombie(void);

	// Member Functions
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
