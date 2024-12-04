#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm " << getName() << " copy constructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }

    if (executor.getGrade() > getExec()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file");
    }

file << "                .        +          .      .          ." << std::endl;
file << "     .            _        .                    ." << std::endl;
file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
file << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
file << ".           \\:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--'.--\"---._/`7" << std::endl;
file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
file << "              \\:  `  X` _| _,\\/   .-'" << std::endl;
file << ".               \":._:`\\____  /:'  /      .           " << std::endl;
file << "                    \\::.  :\\/:'  /              +" << std::endl;
file << "   .                 `.:.  /:'  }      ." << std::endl;
file << "           .           ):_(:;   \\           ." << std::endl;
file << "                      /:. _/ ,  |" << std::endl;
file << "                   . (|::.     ,`               " << std::endl;
file << "     .                |::.    {" << std::endl;
file << "                      |::.\\  \\ `." << std::endl;
file << "                      |:::(\\    |" << std::endl;
file << "              O       |:::/{ }  |                  (o" << std::endl;
file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
file << "      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;

    file.close();

    std::cout << "Shrubbery created: " << _target + "_shrubbery" << std::endl;
}
