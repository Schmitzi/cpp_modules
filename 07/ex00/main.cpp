#include "whatever.hpp"

class Test {
    public:
        Test(const int test) : _test(test){};
        int getTestValue() const { return _test; }
        bool operator<(const Test& other) const {
            return _test < other._test;
        }

        bool operator>(const Test& other) const {
            return _test > other._test;
        }
    private:
        int _test;
};

std::ostream& operator<<(std::ostream& os, const Test& obj) {
    os << obj.getTestValue();
    return os;
}

int main() {
    std::cout << "\t----- Int -----\n" << std::endl;
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << "\n\t----- String -----\n" << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


    std::cout << "\n\t----- Float -----\n" << std::endl;
    float e = 42.24;
    float f = 84.48;

    ::swap(e, f);
    std::cout << "swap(e, f)\te = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f):\t" << ::min(e, f) << std::endl;
    std::cout << "max(e, f):\t" << ::max(e, f) << std::endl;

    std::cout << "\n\t----- Double -----\n" << std::endl;

    double g = 42;
    double h = 84.48;

    ::swap(g, h);
    std::cout << "swap(g, h)\tg = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h):\t" << ::min(g, h) << std::endl;
    std::cout << "max(g, h):\t" << ::max(g, h) << std::endl;

    std::cout << "\n\t----- Classes -----\n" << std::endl;

    Test test1(10);
    Test test2(20);

    ::swap(test1, test2);
    std::cout << "swap(test1, test2)\ttest1 = " << test1 << ", test2 = " << test2 << std::endl;
    std::cout << "min(test1, test2):\t" << ::min(test1, test2) << std::endl;
    std::cout << "max(test1, test2):\t" << ::max(test1, test2) << std::endl;

    return 0;
}
