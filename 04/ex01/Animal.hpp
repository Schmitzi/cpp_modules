#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string type);
		Animal& operator=(const Animal& A);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType(const std::string& type);
};

#endif
