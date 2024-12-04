#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern {
    public:
        Intern();
        //Intern(const Intern& other);
        Intern& operator=(const Intern& S);
        ~Intern();
        AForm* makeForm(const std::string& name, const std::string& form);
	    AForm* createShrubberyCreationForm(const std::string& target);
	    AForm* createRobotomyRequestForm(const std::string& target);
	    AForm* createPresidentialPardonForm(const std::string& target);

};

#endif
