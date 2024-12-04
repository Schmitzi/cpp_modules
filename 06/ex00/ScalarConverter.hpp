#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <limits>

class ScalarConverter {
    public:
        static void convert(const std::string& input);
        static bool isChar(const std::string& value);
        static bool isInt(const std::string& value);
        static bool isFloat(const std::string& value);
        static bool isNan(double value);
        static bool isInf(double value);
        static bool isDouble(const std::string& value);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter &S);
        ~ScalarConverter();
};

#endif