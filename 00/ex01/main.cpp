#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	
	while (std::cin) {
		std::cout << "\nWhat would you like to do?" << std::endl;
		std::cout << "1. ADD contact" << std::endl;
		std::cout << "2. SEARCH for contact" << std::endl;
		std::cout << "3. EXIT" << std::endl;

		if (!std::getline(std::cin, input)) {
			std::cout << "\nExiting program." << std::endl;
			break;
		}
		if (input == "ADD") {
		    phonebook.addContact();
		}
		else if (input == "SEARCH") {
			if (phonebook.getNotEmpty() != 0)
				phonebook.searchContacts();
			else
        		std::cout << "\nNo contacts available to display." << std::endl;
		}
		else if (input == "EXIT") {
			std::cout << "\nGoodbye" << std::endl;
			return (0);
		}
		else {
			std::cout << "Bad input, try again" << std::endl;
        }
	}
	return (0);
}
