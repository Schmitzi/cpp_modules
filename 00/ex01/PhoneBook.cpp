#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->notEmpty = false;
	this->contactCount = 0;
	this->totalContacts = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact()
{
	if (contactCount > 7) {
		contactCount = (contactCount) % 8;
	}

	Contact &contact = contacts[contactCount];
        std::cout << "\nWhat is their first name?" << std::endl;
    	inputCheck(contact, &Contact::setFirstName);

    	std::cout << "What is their last name?" << std::endl;
    	inputCheck(contact, &Contact::setLastName);

    	std::cout << "What is their nick name?" << std::endl;
    	inputCheck(contact, &Contact::setNickName);

    	std::cout << "What is their phone number?" << std::endl;
    	isNum(contact, &Contact::setPhoneNumber);

    	std::cout << "What is their darkest secret?" << std::endl;
    	inputCheck(contact, &Contact::setDarkSecret);
	incrementCounters();
}

void PhoneBook::searchContacts() {
    std::cout << "\n---------------------------------------------" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                PhoneBook                  |" << std::endl;
	std::cout << "|                                           |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < (totalContacts > 7 ? 8 : totalContacts); i++) {
        std::cout << "|" << std::setw(10) << std::right << i + 1 << "|"; 
        writer(contacts[i].getFirstName());
        std::cout << "|";
        writer(contacts[i].getLastName());
        std::cout << "|";
        writer(contacts[i].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
	while (std::cin) {
		std::cout << "\nEnter the index of the contact to display details (or type 'back' to return): ";
        int index = displayContacts(totalContacts);
        
        if (index == -1) {
            return;
        }
        if (index == -2) {
            continue;
        }
        const Contact &contact = contacts[index];
        std::cout << "\nCertainly! Here you go:\n" << std::endl;
        std::cout << "First Name:\t" << contact.getFirstName() << std::endl;
        std::cout << "Last Name:\t" << contact.getLastName() << std::endl;
        std::cout << "Nickname:\t" << contact.getNickName() << std::endl;
        std::cout << "Phone Number:\t" << contact.getPhoneNumber() << std::endl;
        std::cout << "Dark Secret:\t" << contact.getDarkSecret() << std::endl;
    }
}

void PhoneBook::incrementCounters() {
	contactCount++;
    	if (contactCount > 7) {
        	contactCount = contactCount % 8;
	}
    	if (totalContacts < 8) {
		totalContacts++;
	}
	notEmpty = true;
}

int PhoneBook::getTotalContacts() const {
	return totalContacts;
}

int PhoneBook::getNotEmpty() const {
	return notEmpty;
}
