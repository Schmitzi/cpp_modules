#include "ClapTrap.hpp"

int main(void) {
	ClapTrap attacker("Attacker");
    ClapTrap target("Target");
    attacker.attack("Target");

	//ClapTrap clapTrap("Weakling");
    //clapTrap.takeDamage(clapTrap.getHitPoints());
	//clapTrap.attack("Target");

	//ClapTrap clapTrap("Exhausted");
    //for (int i = 0; i < 10; ++i) {
    //    clapTrap.attack("Target");
    //}
    //clapTrap.attack("Target");
	//clapTrap.beRepaired(10);

	return 0;
}
