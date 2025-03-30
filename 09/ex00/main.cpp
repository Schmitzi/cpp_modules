#include "BitcoinExchange.hpp"

int    inputChecker(std::string inputDb) {
    if (inputDb == "data.csv" || inputDb.length() < 4 || 
        (inputDb.substr(inputDb.length() - 4) != ".csv" && inputDb.substr(inputDb.length() - 4) != ".txt")) {
        std::cerr << "Error: bad input database\n";
        return 1;
    }

    std::ifstream inputFile(inputDb.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file: " << inputDb << std::endl;
        return 1;
    }
    inputFile.close();

    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open()) {
        std::cerr << "Error: could not open reference" << std::endl;
        return 1;
    }
    dataFile.close();
    return 0;
}


int main(int ac, char** av) {
    BitcoinExchange btc;
    if (ac != 2) {
        std::cerr << "Error: could not open file. Usage: ./btc <input_file.csv/.txt>" << std::endl;
        return -1;
    }
    
    std::string inputDb = av[1];
    
    if (inputChecker(inputDb)) {
        return -1;
    }

    DataMap refDb;
    btc.grabDataMap("data.csv", refDb);
    if (refDb.empty()) {
        return -1;
    }

    if (!btc.makeDB(inputDb)) {
        return -1;
    }

    btc.findDates(inputDb); 
    btc.calculate();
  
    return 0;
}
