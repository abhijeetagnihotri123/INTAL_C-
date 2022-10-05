#ifndef _ADDITION_H_
#define _ADDITION_H_
#include "APPEND_ZERO.h"

class ADDITION:public APPEND_ZERO
{   
    public:
        ADDITION(void) = default;
        string add_number(string,string);
        virtual ~ADDITION(void) = default;
};
#endif
