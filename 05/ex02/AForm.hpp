#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
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

        AForm();
        AForm(const std::string& name, int grade, int exec);
        AForm& operator=(const AForm& F);
        ~AForm();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGrade() const;
        int getExec() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;

};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif

