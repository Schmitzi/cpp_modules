#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _isSigned(false),_grade(0), _exec(0) {
    std::cout << "Form default constructed" << std::endl;
}

Form::Form(const std::string& name, int grade, int exec) : _name(name), _isSigned(false), _grade(grade), _exec(exec) {
    if (grade < 1 || exec < 1)
        throw GradeTooHighException();
    if (grade > 150 || exec > 150)
        throw GradeTooLowException();
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& F) {
    if (this != &F) {
        _isSigned = F._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form deconstructed" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGrade() const {
    return _grade;
}

int Form::getExec() const {
    return _exec;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _grade)
        throw GradeTooLowException();
    _isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Form& form) {
    output << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
           << ", grade required to sign: " << form.getGrade()
           << ", grade required to execute: " << form.getExec();
    return output;
}

