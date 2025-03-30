#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);;

        std::cout << "Found in vector: " << *easyfind(vec, 3) << "\n";
        std::cout << "Found in list: " << *easyfind(lst, 40) << "\n";

        std::cout << "Finding non-existent value: " << *easyfind(vec, 100) << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
