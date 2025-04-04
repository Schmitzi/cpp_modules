#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

int main() {
	std::cout << "----- First Main -----\n" << std::endl;

    //const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout <<  j->getType() << " " << std::endl;
    std::cout <<  i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    //meta->makeSound();

	//delete meta;
	delete i;
	delete j;  

    std::cout << "\n----- Wrong Animal ----- \n" << std::endl;

	//const WrongAAnimal* meta1 = new WrongAAnimal();
    const WrongAAnimal* k = new WrongCat();

    std::cout <<  k->getType() << " " << std::endl;
    k->makeSound();
    //meta1->makeSound();

	//delete meta1;
	delete k;

	std::cout << "\n----- Brain Test -----\n" << std::endl;

	Dog* basic = new Dog;
    basic->setIdea(0, "Chase cat");
    const Dog* temp = new Dog(*basic);

    std::cout << "\nBasic's sound: ";
	basic->makeSound();
    std::cout << "Basic's idea: " << basic->getIdea(0) << std::endl;

	std::cout << std::endl;
	delete basic;

	std::cout << "\nTemp's sound: ";
	temp->makeSound();
    std::cout << "Temp's idea: " << temp->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete temp;

    std::cout << "\n----- From Subject -----" << std::endl;

    AAnimal* animals[10];
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << std::endl;
        if (i % 2 == 0) {
            animals[i] = new Cat();
        } else {
            animals[i] = new Dog();
        }
        animals[i]->makeSound();
        std::cout << std::endl;
    }

     for (int i = 0; i < 10; i++) {
        delete animals[i];    
    }

	//// Third Main
	std::cout << "\n----- Create Animals -----\n" << std::endl;
    AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();
	
	std::cout << "\n----- Animal Types -----\n" << std::endl;

    std::cout << dog->getType() << std::endl;
    dog->makeSound();
    dog->setType("Chase the cat");
    std::cout << "Dog's idea: " << dog->getType() << std::endl;

	std::cout << cat->getType() << std::endl;
    cat->makeSound();
    cat->setType("Climb the tree");
    std::cout << "Cat's idea: " << cat->getType() << std::endl;

	std::cout << "\n----- Free Animals -----\n" << std::endl;
	delete dog;
	delete cat;

    return 0;
}

