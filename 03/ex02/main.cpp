#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap("ClapMaster");
    ScavTrap scav("Guardian");
    FragTrap frag("Attacker");

    clap.attack("Enemy");
    scav.attack("Intruder");
    scav.guardGate();
    frag.attack("Foe");

    std::cout << "\n--- Testing FragTrap's High Five ---" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n--- Testing FragTrap Energy Depletion ---" << std::endl;
    for (int i = 0; i < 100; ++i) {
        frag.attack("Enemy");
    }
    frag.attack("Enemy");

    std::cout << "\n--- Testing FragTrap with Zero Hit Points ---" << std::endl;
    frag.takeDamage(150); 
    frag.attack("Enemy");
    frag.beRepaired(50);


	//ScavTrap scav("Guardian");

    //scav.attack("Intruder");

    //scav.guardGate();

    //std::cout << "\n--- Testing energy depletion during attacks ---" << std::endl;
    //for (int i = 0; i < 50; ++i) {
    //    scav.attack("Enemy");
    //}
    //scav.attack("Enemy"); 

    //std::cout << "\n--- Testing damage exceeding current hit points ---" << std::endl;
    //scav.takeDamage(150);
    //scav.attack("Enemy");
    //
    //std::cout << "\n--- Testing repair with zero energy and zero hit points ---" << std::endl;
    //scav.beRepaired(20); 

   
    //std::cout << "\n--- Testing new ScavTrap functionality after one is exhausted ---" << std::endl;
    //ScavTrap scavNew("Resilient");
    //scavNew.attack("New Target");

    return 0;
}

