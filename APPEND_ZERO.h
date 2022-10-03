#ifndef _APPEND_ZERO_H_
#define _APPEND_ZERO_H_
#include <string>
#include <iostream>
using namespace std;

class APPEND_ZERO
{
    public:
        APPEND_ZERO(void) = default;
        void reverse(string&);
        string removeLeadingZeros(string);
        void append_zero(string&,int);
        virtual ~APPEND_ZERO(void) = default;
};

#endif