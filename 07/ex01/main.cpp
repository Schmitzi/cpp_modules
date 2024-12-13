#include "iter.hpp"

class Test {
    public:
        Test(const int test) : _test(test){};
        int getTest() const { return _test; }
    private:
        int _test;
};

std::ostream& operator<<(std::ostream& os, const Test& obj) {
    os << obj.getTest();
    return os;
}

template <typename T>
void increment(T& elem) {
    ++elem;
}

template <typename T>
void decrement(T& elem) {
    --elem;
}

template <typename T>
void print(const T& elem) {
    std::cout << "[" << elem << "]" << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "\t----- Integer Array -----\n";
    std::cout << "Original: ";
    iter(intArray, intLen, print<int>);
    std::cout << "\nIncremented: ";
    iter(intArray, intLen, increment<int>);
    iter(intArray, intLen, print<int>);
    std::cout << "\nDecremented: ";
    iter(intArray, intLen, decrement<int>);
    iter(intArray, intLen, print<int>);
    std::cout << "\n";

    double floatArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t floatLen = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "\n\t----- Floating-Point Array -----\n";
    iter(floatArray, floatLen, print<double>);
    std::cout << "\n";

    char charArray[] = {'A', 'B', 'C', 'D'};
    size_t charLen = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "\n\t----- Character Array -----\n";
    iter(charArray, charLen, print<char>);
    std::cout << "\n";

    std::string strArray[] = {"Hello", "World", "C++"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "\n\t----- String Array -----\n";
    iter(strArray, strLen, print<std::string>);
    std::cout << "\n";

	const char constStrArray[] = "Hello, World!";
    size_t constStrLen = sizeof(constStrArray) / sizeof(constStrArray[0]) - 1;
    std::cout << "\n\t----- Const Char Array -----\n";
    iter(constStrArray, constStrLen, print<char>);
    std::cout << "\n";

    Test test[] = {10, 20, 30, 40};
    size_t testLen = sizeof(test) / sizeof(test[0]);
    std::cout << "\n\t----- Class -----\n";
    iter(test, testLen, print<Test>);
    std::cout << "\n";

    std::string stringArray1 = "Hello, World!";
    size_t str1Len = stringArray1.size();
    std::cout << "\n\t----- String Array 1 -----\n";
    iter(stringArray1.data(), str1Len, print<char>);
    std::cout << "\n";

    std::string stringArray2 = "Hello, World!";
    std::cout << "\n\t----- String Array 2 -----\n";
    iter(stringArray2.data(), 13, print<char>);
    std::cout << "\n";

    const char stringArray3[14] = "Hello, World!";
    std::cout << "\n\t----- String Array 3 -----\n";
    iter(stringArray3, 13, print<char>);
    std::cout << std::endl;


    return 0;
}