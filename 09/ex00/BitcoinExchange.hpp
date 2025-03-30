#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <string.h>
#include <iomanip>

typedef std::map<std::string, double> DataMap;

enum Error
{
	BAD_FILE = 1,
	NOT_POS = 2,
	TOO_BIG = 3,
	NO_DB = 4,
    FEB_ERR = 5,
    RANGE = 6
};

class BitcoinExchange {
    public:
        // OOF
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        // Calculate price
        void            multiply(const std::string& date, const double& amount);

        // Parsing
		int             grabDataMap(const std::string& file, DataMap &dest);
		void            findDates(const std::string& file);
        bool            dateChecker(const std::string& date);
        bool            makeDB(const std::string& file);
        void            calculate();
        void            printDb(const DataMap db);
        int             leapYearCheck(int* date);
        int             monthCheck(int* date);

        // Setters/Getters
        const DataMap&  getRefDb() const;
        void            setRefDb(const DataMap& refDb);

        // Error Handling
        void            error(Error e, const std::string str);

    private:
        DataMap         _ref_db;
        std::string     *_inputDb;
        size_t          _inputSize;
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& btc);

#endif
