#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>

class RPN {
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();

        void                splitString(char *input);
        bool                calculateNumber();
        bool                checkMembers();

        int                 getCalcStack();

    private:
        std::stack<char*, std::list<char*> >   _input;
        std::stack<long, std::list<long> >     _calcStack;
};

#endif