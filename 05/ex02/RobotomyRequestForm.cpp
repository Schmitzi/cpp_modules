#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm " << getName() << " copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& S) {
    if (this != &S) {
        AForm::operator=(S);
        _target = S._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }

    if (executor.getGrade() > getExec()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "*BRRRRRRRRRRRRRRRRRRR*" << std::endl;
    srand(static_cast<unsigned int>(time(0)));

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        std::cout << "Robotomy was successful!" << std::endl;
    } else {
        std::cout << "Robotomy failed!" << std::endl;
    }
}