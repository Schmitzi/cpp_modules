#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructed" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
    std::cout << "ScalarConverter copy constructed" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter deconstructed" << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    if (isChar(input))
    {
        std::cout << "char: '" << input << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
    }
    else if (isInt(input))
    {
        int value = std::atoi(input.c_str());
        if (isalpha(value))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << value << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    } 
    else if (isFloat(input))
    {
        float value = std::strtof(input.c_str(), NULL);
        if (isNan(value) || isInf(value))
            std::cout << "char: impossible" << std::endl;
        else if (value >= 32 && value <= 126)
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (isNan(value) || isInf(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
    else if (isDouble(input))
    {
        double value = std::strtod(input.c_str(), NULL);
        if (isNan(value) || isInf(value))
            std::cout << "char: impossible" << std::endl;
        else if (value >= 32 && value <= 126)
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (isNan(value) || std::isinf(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
    else {
        std::cout << "Error: Invalid input" << std::endl;
    }
}

bool    ScalarConverter::isChar(const std::string& value) {
    if (value.length() == 1 && isprint(value[0]) && !isdigit(value[0]))
        return (true);
    return (false);
}

bool    ScalarConverter::isInt(const std::string& input) {
    char* end;
    long value = std::strtol(input.c_str(), &end, 10);
    return *end == '\0' && value >= INT_MIN && value <= INT_MAX;
}

bool    ScalarConverter::isNan(double value) {
    return value != value;
}

bool ScalarConverter::isInf(double input) {
    return input == std::numeric_limits<double>::infinity() ||
           input == -std::numeric_limits<double>::infinity();
}

bool ScalarConverter::isFloat(const std::string& input) {
    char* end;
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    std::strtof(input.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& input) {
    char* end;
    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;
    std::strtod(input.c_str(), &end);
    return *end == '\0';
}