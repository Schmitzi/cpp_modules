#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

    std::cout << "----- Included main -----\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout <<  j->getType() << " " << std::endl;
    std::cout <<  i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete i;
	delete j;

    std::cout << "\n----- Wrong Animal ----- \n" << std::endl;

	const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout <<  k->getType() << " " << std::endl;
    k->makeSound();
    meta1->makeSound();

	delete meta1;
	delete k;

	return 0;
}

