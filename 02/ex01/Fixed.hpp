#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int num;
        static const int bit = 8;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed(const int num);
        Fixed(float num);
        ~Fixed();
        Fixed& operator=(const Fixed& f);

        float toFloat(void) const;
        int toInt(void) const ;
        int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& output, const Fixed& D);
