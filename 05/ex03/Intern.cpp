#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default contructor called" << std::endl;
}

//Intern::Intern(const Intern& other) {
//    (void)other;
//    std::cout << "Intern copy contructor called" << std::endl;
//}

Intern& Intern::operator=(const Intern& S) {
    if (this != &S) {
        // Nothing to copy
    }
    return (*this);
}

Intern::~Intern() {
    std::cout << "Intern deconstructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& form) {
    struct FormCreator {
        std::string formName;
        AForm* (Intern::*createFunc)(const std::string&);
    };

    static const FormCreator formCreators[] = {
        {"ShrubberyCreationForm", &Intern::createShrubberyCreationForm},
        {"RobotomyRequestForm", &Intern::createRobotomyRequestForm},
        {"PresidentialPardonForm", &Intern::createPresidentialPardonForm},
    };

    for (size_t i = 0; i < sizeof(formCreators) / sizeof(FormCreator); ++i) {
        if (formCreators[i].formName == form) {
            std::cout << "\nIntern creates " << form << std::endl;
            return (this->*(formCreators[i].createFunc))(name);
        }
    }

    std::cerr << "Error: Form \"" << name << "\" does not exist." << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

