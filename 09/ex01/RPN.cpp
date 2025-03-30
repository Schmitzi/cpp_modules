#include "RPN.hpp"

RPN::RPN() { 
}

RPN::RPN(const RPN& other) : _input(other._input), _calcStack(other._calcStack) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _input = other._input;
        _calcStack = other._calcStack; 
    }
    return *this;
}

RPN::~RPN() {
}

int RPN::getCalcStack() {
    return _calcStack.top();
}

void RPN::splitString(char *input) {

    char *tokens = strtok(input, " ");

    std::stack<char*> tempStack;
    
    while (tokens != NULL) {

        tempStack.push(tokens);
        tokens = strtok(NULL, " ");
    }

    while (!tempStack.empty()) {
        _input.push(tempStack.top());
        tempStack.pop();
    }
}

bool RPN::checkMembers() {

    std::stack<char*, std::list<char*> > tempNums = _input;

    while (!tempNums.empty()) { //isdigit
        if (std::ispunct(tempNums.top()[0]) ) {
            if (strlen(tempNums.top()) > 1)  {
                std::cerr << "Error: bad operator" << std::endl;
                return false;
            }
        }
        else  {
            if (strlen(tempNums.top()) > 1 || std::atoi(tempNums.top()) > 9) {
                std::cerr << "Error: number too high: " << tempNums.top() << std::endl;
                return false;
            }
            else if (std::atoi(tempNums.top()) < 0) {
                std::cerr << "Error: number too low: " << tempNums.top() << std::endl;
                return false;
            }
        }
        tempNums.pop();
    }
    return true;
}


bool RPN::calculateNumber() {

    while (!_input.empty()) {
        if (isdigit(_input.top()[0])) {
            _calcStack.push(std::atoi(_input.top()));
        } else {
            if (_calcStack.size() < 2) {
                std::cerr << "Error: Invalid expression" << std::endl;
                return false;
            }
           
            long tempNum = _calcStack.top();
            _calcStack.pop();
            
            if (strcmp(_input.top(), "+") == 0) {
                _calcStack.top() += tempNum;
            }
            else if (strcmp(_input.top(), "-") == 0) {
                _calcStack.top() -= tempNum;
            }
            else if (strcmp(_input.top(), "*") == 0) {
                _calcStack.top() *= tempNum;
            }
            else if (strcmp(_input.top(), "/") == 0) {
                if (tempNum == 0 || _calcStack.top() == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return false;
                }
                _calcStack.top() /= tempNum;
            }
        }
        _input.pop();
        if (_calcStack.top() > std::numeric_limits<int>::max() || _calcStack.top() < std::numeric_limits<int>::min()) {
            std::cerr << "Error: Overflowed" << std::endl;
            return false;
        }
    }

    if (_calcStack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return false;
    }

    return true;
}
