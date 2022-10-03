#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_
#include "ADDITION.h"
#include "SUBTRACTION.h"

class MULTIPLICATION:private ADDITION,private SUBTRACTION
{
    public:
        MULTIPLICATION() = default;
        string multiply(string,string);
        string multiply_aux(string,string);
        string removeLeadingZeros(string);
        virtual ~MULTIPLICATION() = default;
};

#endif