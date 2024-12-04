#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Bureaucrat {
	private:
	    const std::string	_name;
	    int 				_grade;
	
	public:
		//	OCF	
		Bureaucrat();
	    Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat& operator=(const Bureaucrat& B);
	    ~Bureaucrat();

	    // Exception classes
	    class GradeTooHighException : public std::exception {
	    public:
	        const char* what() const throw() {
	            return "Grade is too high!";
	        }
	    };
	    class GradeTooLowException : public std::exception {
	    public:
	        const char* what() const throw() { 
	            return "Grade is too low!";
	        }
	    };

		// Member Functions
		void incrementGrade();
	    void decrementGrade();
		void signForm(Form& form);

		// Getters
	    const std::string& getName() const;
	    int getGrade() const;

	    
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b);

#endif

