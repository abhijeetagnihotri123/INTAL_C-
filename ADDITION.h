#ifndef _ADDITION_H_
#define _ADDITION_H_
#include "APPEND_ZERO.h"

class ADDITION:private APPEND_ZERO
{   
    public:
        ADDITION(void) = default;
        string add_number(string,string);
        virtual ~ADDITION(void) = default;
};
#endif
