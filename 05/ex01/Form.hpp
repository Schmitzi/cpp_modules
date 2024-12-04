#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _grade;
        const int           _exec;

    public:
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form grade is too high!";
            }
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form grade is too low!";
            }
        };

        Form();
        Form(const std::string& name, int grade, int exec);
        Form& operator=(const Form& F);
        ~Form();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGrade() const;
        int getExec() const;

        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& output, const Form& form);

#endif

