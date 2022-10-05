#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_
#include "ADDITION.h"
#include <iostream>

class MULTIPLICATION:public ADDITION
{
    public:
        MULTIPLICATION() = default;
        string multiply_with_single_digit(string,char);
        string multiply(string,string);
        virtual ~MULTIPLICATION() = default;
};

#endif