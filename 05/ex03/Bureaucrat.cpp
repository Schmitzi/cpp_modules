#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(0) {
    std::cout << "Bureaucrat default constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat " << _name << " constructed" << std::endl;
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B) {
    if (this != &B) {
        //_name = B.getName();
        _grade = B._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    if (_name != "") {
        std::cout << "Bureaucrat " << _name <<  " decontructed" << std::endl;
    } else {
        std::cout << "Bureaucrat decontructed" << std::endl;
    }
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
   try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b) {
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return output;
}

