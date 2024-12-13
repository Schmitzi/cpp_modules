#include "Array.hpp"

int main() {
    try {
        std::cout << "\t\t----- Int Output -----\n" << std::endl;
        Array<int> defaultArray;
        std::cout << "Default array:\t\t" << defaultArray << std::endl;

        Array<int> paramArray(5);
        for (unsigned int i = 0; i < paramArray.getSize(); ++i)
            paramArray[i] = (i + 1) * 10;
        std::cout << "Parameterized array:\t" << paramArray << std::endl;

        Array<int> copyArray(paramArray);
        std::cout << "Copied array:\t\t" << copyArray << std::endl;

        Array<int> assignArray;
        assignArray = paramArray;
        std::cout << "Assigned array:\t\t" << assignArray << std::endl;

        std::cout << "Element at index 3: " << paramArray[3] << std::endl;

        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << paramArray[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\nException: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n\t\t----- String Output -----\n" << std::endl;
        Array<std::string> strArray;
        std::cout << "Default array:\t\t" << strArray << std::endl;

        Array<std::string> strParamArray(5);
        strParamArray[0] = "This";
        strParamArray[1] = "is";
        strParamArray[2] = "a";
        strParamArray[3] = "test";
        strParamArray[4] = "array";
        std::cout << "Parameterized array:\t" << strParamArray << std::endl;

        Array<std::string> strCopyArray(strParamArray);
        std::cout << "Copied array:\t\t" << strCopyArray << std::endl;

        Array<std::string> strAssignArray;
        strAssignArray = strParamArray;
        std::cout << "Assigned array:\t\t" << strAssignArray<< std::endl;

        std::cout << "Element at index 3: " << strParamArray[3] << std::endl;

        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << strParamArray[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\nException: " << e.what() << std::endl;
    }

    return 0;
}
