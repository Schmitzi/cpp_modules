#pragma once

#include <iostream>

class Zombie {
	private:
		std::string	name;

	public:
		// Constructors
		Zombie();
		~Zombie();

		// Member Functions
		void announce();

		// Setter
		void setName( std::string name );
};
