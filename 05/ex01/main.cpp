#include "Bureaucrat.hpp"

int main() {
    std::cout << "\t----- First -----\n" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment:\n" << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement:\n" << bob << std::endl;

        Bureaucrat alice("Alice", 0);  
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }

    std::cout << "\n\t----- Second -----\n" << std::endl;

    try {
        Bureaucrat john("John", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }

    std::cout << "\n\t----- Third -----\n" << std::endl;

    try {
        Bureaucrat b;

        std::cout << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getGrade() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }

    std::cout << "\n\t----- Fourth -----\n" << std::endl;

    try {
        Form taxForm("Tax Form", 50, 25);
        Bureaucrat lowLevel("Low Level Bureaucrat", 100);
        Bureaucrat highLevel("High Level Bureaucrat", 10);

        lowLevel.signForm(taxForm);
        highLevel.signForm(taxForm);

    }
    catch (const Form::GradeTooHighException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }

    return 0;
}
