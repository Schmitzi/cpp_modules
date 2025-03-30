#include "RPN.hpp"

bool inputChecker(const char *word) {
    const char* allowed = "0123456789+-/* ";

    for (size_t i = 0; word[i] != '\0'; i++) {
        if (!std::strchr(allowed, word[i])) {
            return false;
        }
    }
    return true;
}

int main(int ac, char** av)
{
    if (ac < 2) {
        std::cout << "Please add expressions" << std::endl;
        return 1;
    }

    if (inputChecker(av[1]) == false) {
        std::cerr << "Error: invalid characters in input" << std::endl;
        return 1;
    }

    RPN rpn;

    rpn.splitString(av[1]);

    if (!rpn.checkMembers() || !rpn.calculateNumber()) {
        return 1;
    }

    std::cout << "Result: " << rpn.getCalcStack() << std::endl;
    
    return 0;
}