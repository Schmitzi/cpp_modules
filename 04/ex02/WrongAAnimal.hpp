#ifndef WRONGAANIMAL_HPP
#define WRONGAANIMAL_HPP

#include <iostream>

class WrongAAnimal {
    protected:
        std::string _type;
    public:
        WrongAAnimal();
        WrongAAnimal(const std::string type);
        WrongAAnimal& operator=(const WrongAAnimal& A);
        virtual ~WrongAAnimal();

        virtual void    makeSound() const = 0;
        std::string     getType() const;
        void            setType(const std::string& type);
};

#endif

