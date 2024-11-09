#pragma once

#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		//Constructors
		Weapon( std::string type );
		~Weapon();

		// Setters & Getters
		const std::string&	getType();
		void	setType(std::string type);
};
