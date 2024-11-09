#pragma once

#include <iostream>
#include <string>

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
        typedef void (Harl::*HarlFunc)();
        struct ComplaintHandler {
            std::string level;
            HarlFunc func;
        };
    
    public:
        void complain( std::string level );
};