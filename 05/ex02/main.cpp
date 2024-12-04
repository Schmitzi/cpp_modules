#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    std::cout << "----- First -----\n" << std::endl;
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

    std::cout << "\n----- Second -----\n" << std::endl;

    try {
        Bureaucrat john("John", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "\nException:\n" << e.what() << std::endl;
    }

    std::cout << "\n----- Third -----\n" << std::endl;

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

    std::cout << "\n----- Fourth -----\n" << std::endl;

    try {
        ShrubberyCreationForm shrub("Garden");
        Bureaucrat lowLevel("Low Level Bureaucrat", 150);
        Bureaucrat highLevel("High Level Bureaucrat", 1);

        std::cout << "\n--- Attempting to execute with low-level bureaucrat ---\n";
        lowLevel.signForm(shrub);
        lowLevel.executeForm(shrub);

        std::cout << "\n--- Signing and executing with high-level bureaucrat ---\n";
        highLevel.signForm(shrub);
        highLevel.executeForm(shrub);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- Fifth -----\n" << std::endl;

    try {
        RobotomyRequestForm robot("Marvin");
        Bureaucrat lowLevel("Low Level Bureaucrat", 150);
        Bureaucrat highLevel("High Level Bureaucrat", 1);

        std::cout << "\n--- Attempting to execute with low-level bureaucrat ---\n";
        lowLevel.signForm(robot);
        lowLevel.executeForm(robot);

        std::cout << "\n--- Signing and executing with high-level bureaucrat ---\n";
        highLevel.signForm(robot);
        highLevel.executeForm(robot);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- Sixth -----\n" << std::endl;

    try {
        PresidentialPardonForm pres("Trump");
        Bureaucrat lowLevel("Low Level Bureaucrat", 150);
        Bureaucrat highLevel("High Level Bureaucrat", 1);

        std::cout << "\n--- Attempting to execute with low-level bureaucrat ---\n";
        lowLevel.signForm(pres);
        lowLevel.executeForm(pres);

        std::cout << "\n--- Signing and executing with high-level bureaucrat ---\n";
        highLevel.signForm(pres);
        highLevel.executeForm(pres);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
