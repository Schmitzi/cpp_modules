#include "Bureaucrat.hpp"

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

    return 0;
}
