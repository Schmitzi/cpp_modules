#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _inputDb(NULL), _inputSize(0) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _inputDb(NULL), _inputSize(0) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _ref_db = other._ref_db;
        delete[] _inputDb;
        _inputDb = NULL;
        _inputSize = other._inputSize;
        
        if (other._inputDb != NULL && _inputSize > 0) {
            _inputDb = new std::string[_inputSize];
            for (size_t i = 0; i < _inputSize; i++) {
                _inputDb[i] = other._inputDb[i];
            }
        }
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    if (_inputDb != NULL) {
        delete[] _inputDb;
    }
}

void	BitcoinExchange::findDates(const std::string& file) {
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()) {
        error(BAD_FILE, file);
        return;
    }

    bool isFirstLine = true;
    std::string line;
    size_t index = 0;

    while (std::getline(inputFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        if (index < _inputSize) {
            _inputDb[index] = line;
            index++;
        }
    }
    inputFile.close();
}

bool BitcoinExchange::makeDB(const std::string& file) {
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()) {
        error(BAD_FILE, file);
        return false;
    }

    std::string line;
    bool isFirstLine = true;
    size_t lineCount = 0;

    while (std::getline(inputFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        lineCount++;
    }

    _inputSize = lineCount;
    _inputDb = new std::string[lineCount];
    inputFile.close();
    return true;
}

void BitcoinExchange::calculate() {
    std::string inputDate;
    double inputAmount;
    const char *allowed = "0123456789.";
    
    for (size_t i = 0; i < _inputSize; i++) {
        inputDate = _inputDb[i].substr(0, _inputDb[i].find('|') - 1);
        std::string amountStr = _inputDb[i].substr(_inputDb[i].find('|') + 1, _inputDb[i].length());
        
        bool isValid = true;
        for (size_t j = 0; j < amountStr.length(); j++) {
            if (!strchr(allowed, amountStr[j]) && amountStr[j] != ' ') {
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            inputAmount = std::atof(amountStr.c_str());
        }
        else {
            std::cerr << "Error: bad input => " << amountStr << std::endl;
            continue;
        }
        multiply(inputDate, inputAmount);
    }
}

int BitcoinExchange::grabDataMap(const std::string& file, DataMap &dest) {
    
    // Check if file exists and can be opened
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()) {
        error(BAD_FILE, file);
        return -1;
    }
    
    // Check if file is empty by peeking at the first character
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        error(NO_DB, "NO DB");
        inputFile.close();
        return -1;
    }
    
    std::string line;
    bool isFirstLine = true;
    bool hasValidData = false;
    
    while (std::getline(inputFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        size_t delimiter = line.find(',');
        if (delimiter == std::string::npos)
            continue;
        
        std::string date;
        std::string valueStr;
        date = line.substr(0, delimiter);
        valueStr = line.substr(delimiter + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        
        try {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(10);
            ss << valueStr;
            double value;
            if (ss >> value) {
                dest[date] = value;
                hasValidData = true;
            }
        } catch (...) {
            continue;
        }
    }
    
    inputFile.close();
    
    // Check if any valid data was found
    if (!hasValidData) {
        error(NO_DB, "NO DB");
        dest.clear();
        return (-1);
    }

    setRefDb(dest); 
    return 0;
}
void BitcoinExchange::printDb(const DataMap db) {
    DataMap::const_iterator it;

    std::cout << "DataMap" << std::endl;
    for (it = db.begin(); it != db.end(); ++it) {
        std::cout << it->first << ": " << std::fixed << std::setprecision(0) << it->second << std::endl;
    }
}

void splitDate(const std::string& date_str, int dates[3]) {
    std::stringstream ss(date_str);
    std::string token;
    for (size_t i = 0; std::getline(ss, token, '-') && i < 3; i++) {
        dates[i] = std::atoi(token.c_str());
    }
}

int BitcoinExchange::leapYearCheck(int* date) {
    if ((date[0] % 400 == 0) || (date[0] % 4 == 0 && date[0] % 100 != 0)) {
        return 0;
    }
    return (-1);
}

bool    BitcoinExchange::dateChecker(const std::string& date) {

    const char* allowed = "0123456789-";

    for (size_t i = 0; date[i] != '\0'; i++) {
        if (!strchr(allowed, date[i])) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }
    }
    
    if (date[4] != '-' || date[7] != '-') {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

        int dateSplit[3];
        splitDate(date, dateSplit);
        
        if (dateSplit[1] < 1 || dateSplit[1] > 12) {
            std::cerr << "Error: month out of range => " << date << std::endl;
            return false;
        }

        if (dateSplit[1] == 2) {
            if (dateSplit[2] > 29) {
                error(FEB_ERR, date);
                return false;
            }
            if (dateSplit[2] == 29 && leapYearCheck(dateSplit) == -1) {
                error(FEB_ERR, date);
                return false;
            }
        }
        else {
            int maxDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (dateSplit[2] < 1 || dateSplit[2] > maxDays[dateSplit[1] - 1]) {
                std::cerr << "Error: date cannot exist => " << date << std::endl;
                return false;
            }
    }
    return true;
}

void BitcoinExchange::multiply(const std::string& date, const double& amount) {
    if (!dateChecker(date)) {
        return;
    }
    if (amount < 0) {
        std::cerr << "Error: not a positive number => " << amount << std::endl;
        return;
    }
    if (amount > 1000) {
        std::cerr << "Error: too large a number => " << amount << std::fixed << std::setprecision(1) << std::endl;
        return;
    }

    DataMap::const_iterator found = _ref_db.find(date);
    if (found != _ref_db.end()) {
        std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(1)
                 << found->second * amount << std::endl;
        return;
    }

    DataMap::const_iterator closest = _ref_db.lower_bound(date);
    
    if (closest == _ref_db.end()) {
        --closest;
        std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(1)
                 << closest->second * amount << " (using rate from " << closest->first << ")" << std::endl;
        return;
    }

    DataMap::const_iterator first = _ref_db.begin();
    if (closest == _ref_db.begin() && closest->first > date) {
        std::cerr << "Error: no data available before " << first->first << " (date given " << date << ")" << std::endl;
        return;
    }

    if (closest->first > date) {
        --closest;
    }

    std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(1)
             << closest->second * amount << " (using rate from " << closest->first << ")" << std::endl;
}

int BitcoinExchange::monthCheck(int* date) {
    int maxDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = date[2];
    
    if (totalDays < 1 || totalDays > maxDays[date[1] - 1]) {
        return -1;
    }
    return 0;
}

const DataMap& BitcoinExchange::getRefDb() const {
    return _ref_db;
}


void BitcoinExchange::setRefDb(const DataMap& refDb) {
    _ref_db = refDb;
}


void BitcoinExchange::error(Error e, const std::string str) 
{
    switch(e)
    {
        case BAD_FILE: 
            std::cerr << "Error: could not open file" << std::endl;
            break;
        case NOT_POS: 
            std::cerr << "Error: not a positive number" << str << std::endl;
            break;
        case TOO_BIG: 
            std::cerr << "Error: too large a number" << std::endl;
            break;
        case NO_DB:
            std::cerr << "Error: data.csv is empty" << std::endl;
            break;
        case FEB_ERR:
            std::cerr << "Error: bad date for February => " << str << std::endl;
            break;
        case RANGE:
            std::cerr << "Error: date is out of range =>" << str << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& btc) {
    const DataMap& ref = btc.getRefDb();
    DataMap::const_iterator it;
    for (it = ref.begin(); it != ref.end(); ++it) {
        os << it->first << " | " << it->second << std::endl;
    }
    return os;
}
