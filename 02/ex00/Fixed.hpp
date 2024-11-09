#pragma once

#include <iostream>

class Fixed
{
    private:
        int num;
        static const int bit = 8;

    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed& operator=(const Fixed& f);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits (int const raw);
};

