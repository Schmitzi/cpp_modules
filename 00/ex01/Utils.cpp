#include "Utils.hpp"

void    writer(const std::string& str) {
    if (str.length() > 9)
        std::cout << std::setw(10) << std::right << str.substr(0, 9) + ".";
    else 
        std::cout << std::setw(10) << std::right << str;
}

void isNum(Contact& contact, void (Contact::*setter)(const std::string&)) {
    std::string num;

    while (true) {
        bool hasDigit = false;
        if (!std::getline(std::cin, num)) {
            std::cout << "\nEOF detected." << std::endl;
            exit(-1);
        }
        if (num.empty()) {
            std::cout << "String is empty. Please try again." << std::endl;
            continue;
        }
        for (size_t i = 0; i < num.length(); ++i) {
            if (std::isdigit(num[i])) {
                hasDigit = true;
            } else {
                std::cout << "Not a valid phone number. Please try again." << std::endl;
                hasDigit = false;
                break;
            }
        }
        if (!hasDigit) {
            continue;
        }
        (contact.*setter)(num);
        break;
    }
}
int displayContacts(int count) {
    std::string str;
    int index;

    if (!std::getline(std::cin, str)) {
        std::cout << "\nEOF detected." << std::endl;
        exit(-1);
    }
    if (str == "back") {
        return -1;
    }
    std::istringstream is(str);
    if (!(is >> index) || index < 1 || index > count) {
        std::cout << "\nInvalid input. Please enter a valid number or 'back'." << std::endl;
        return -2;
    }
    return index - 1;
}

void inputCheck(Contact& contact, void (Contact::*setter)(const std::string&)) {
    std::string var;
    while (1) {
    	if (!std::getline(std::cin, var)) {
        	std::cout << "\nEOF detected." << std::endl;
        	exit(-1);
   	}
   	for (size_t i = 0; var[i]; i++) {
   		if (var[i] == '\t' || !isascii(var[i])) {
   	        	std::cout << "Invalid input, no tabs or umlauts allowed." << std::endl;
			continue ;
   	     	}
   	 }
   	 if (var.empty()) {
   	     std::cout << "String is empty" << std::endl;
	     continue ;
   	 }
	 break ;
    }
    (contact.*setter)(var);
}
