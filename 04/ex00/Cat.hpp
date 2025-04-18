#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const std::string type);
		Cat& operator=(const Cat& C);
		~Cat();

		void makeSound() const;
};

#endif
