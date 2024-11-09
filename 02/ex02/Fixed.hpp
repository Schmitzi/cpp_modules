#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int num;
        static const int bit = 8; // 8 fractional bits

    public:
        // Constructors
        Fixed();
        Fixed(const Fixed& f);
        Fixed(const int num);
        Fixed(const float num);
        // Destructor
        ~Fixed();

        // Conversion Functions
        float toFloat( void ) const;
        int toInt( void ) const;

        // Getter and Setter
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        // Static min and max functions
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);

        // Operator Overloads
        Fixed& operator=(const Fixed& O);

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Pre-increment and pre-decrement operators
        Fixed& operator++();

        Fixed& operator--();

        // Post-increment and post-decrement operators
        Fixed operator++(int);
        Fixed operator--(int);
};

// Overload << operator
std::ostream& operator<<(std::ostream& output, const Fixed& D);

