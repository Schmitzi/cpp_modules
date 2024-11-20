#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy constructed" << std::endl;
}

Brain& Brain::operator=(const Brain& other) { 
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

std::string Brain::getType(int index) const {
    if (index >= 0 && index < 100)
        return (_ideas[index]);
    else
        return ("");
}

void Brain::setType(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}
