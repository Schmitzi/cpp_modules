#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target){
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& S) {
    if (this != &S) {
        AForm::operator=(S); 
        _target = S._target;
    }
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }
    else if (executor.getGrade() > getExec()) {
        throw AForm::GradeTooLowException();
    }
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}