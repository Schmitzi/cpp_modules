#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {

    Base* obj = generate();
    
    std::cout << "\t----- Output -----" << std::endl;
    std::cout <<"Identify using pointer:\t\t";
    identify(obj);

    std::cout << "Identify using reference:\t";
    identify(*obj);

    delete obj;

    return 0;
}