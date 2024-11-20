#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal& operator=(const WrongAnimal& A);
        virtual ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
        void setType(const std::string& type);
};

#endif

