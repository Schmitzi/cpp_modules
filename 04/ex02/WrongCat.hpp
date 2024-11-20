#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class WrongCat : public WrongAAnimal {
    public:
        WrongCat();
        WrongCat(const std::string type);
        WrongCat& operator=(const WrongCat& C);
        ~WrongCat();

        void makeSound() const;
};

#endif

