#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal& operator=( const AAnimal& A);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		void			setType(const std::string& type);
};

#endif
