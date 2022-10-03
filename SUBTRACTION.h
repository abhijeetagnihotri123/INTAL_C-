#ifndef _SUBTRACTION_H_
#define _SUBTRACTION_H_
#include "LEXICOGRAPHICAL.h"
#include "APPEND_ZERO.h"
using namespace std;

class SUBTRACTION:private LEXICOGRAPHICAL,private APPEND_ZERO
{
    public:
        SUBTRACTION(void) = default;
        string subtract_number(string,string);
        string subtract_number_aux(string,string);
        string removeLeadingZeros(string);
        virtual ~SUBTRACTION() = default;
};

#endif