#ifndef _POWER_H_
#define _POWER_H_
#include "INTAL.h"

class POWER
{
    public:
    POWER(void) = default;
    INTAL nth_power_aux(INTAL,int);
    INTAL nth_power(INTAL,int);
    ~POWER(void) = default;
};

#endif