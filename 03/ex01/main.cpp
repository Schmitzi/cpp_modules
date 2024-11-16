#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	//ClapTrap attacker("Attacker");
    //ClapTrap target("Target");
    //attacker.attack("Target");

	//ClapTrap clapTrap("Weakling");
    //clapTrap.takeDamage(clapTrap.getHitPoints());
	//clapTrap.attack("Target");

	//ClapTrap clapTrap("Exhausted");
    //for (int i = 0; i < 10; ++i) {
    //    clapTrap.attack("Target");
    //}
    //clapTrap.attack("Target");
	//clapTrap.beRepaired(10);
	
    
	ScavTrap scav("Guardian");

    scav.attack("Intruder");

    scav.guardGate();

    std::cout << "\n--- Testing energy depletion during attacks ---" << std::endl;
    for (int i = 0; i < 50; ++i) {
        scav.attack("Enemy");
    }
    scav.attack("Enemy"); 

    std::cout << "\n--- Testing damage exceeding current hit points ---" << std::endl;
    scav.takeDamage(150);
    scav.attack("Enemy");
    
    std::cout << "\n--- Testing repair with zero energy and zero hit points ---" << std::endl;
    scav.beRepaired(20); 

   
    std::cout << "\n--- Testing new ScavTrap functionality after one is exhausted ---" << std::endl;
    ScavTrap scavNew("Resilient");
    scavNew.attack("New Target");

    return 0;
}
