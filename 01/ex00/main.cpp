#include "Zombie.hpp"

int main(void){
	Zombie*	zombie = newZombie("Bort");
	zombie->announce();
	randomChump("Krom");
	delete zombie;
}
