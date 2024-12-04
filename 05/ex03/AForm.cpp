#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _isSigned(false),_grade(0), _exec(0) {
    std::cout << "AForm default constructed" << std::endl;
}

AForm::AForm(const std::string& name, int grade, int exec) : _name(name), _isSigned(false), _grade(grade), _exec(exec) {
    if (grade < 1 || exec < 1)
        throw GradeTooHighException();
    if (grade > 150 || exec > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& F) {
    if (this != &F) {
        _isSigned = F._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    if (_name != "") {
        std::cout << "AForm " << _name <<  " decontructed" << std::endl;
    } else {
        std::cout << "AForm decontructed" << std::endl;
    }
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGrade() const {
    return _grade;
}

int AForm::getExec() const {
    return _exec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    try {
        if (bureaucrat.getGrade() > _grade)
            throw GradeTooLowException();
        _isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
    } catch (const AForm::GradeTooLowException& e){
        std::cout << _name << " couldn’t sign " << getName()
                  << " because " << e.what() << std::endl;
    }
}

// void AForm::execute(Bureaucrat const & executor) const {

//}

std::ostream& operator<<(std::ostream& output, const AForm& AForm) {
    output << "AForm " << AForm.getName() << ", signed: " << (AForm.getIsSigned() ? "yes" : "noA")
           << ", grade required to sign: " << AForm.getGrade()
           << ", grade required to execute: " << AForm.getExec();
    return output;
}

