#include "POWER.h"

INTAL POWER::nth_power(INTAL base,int power)
{
    if(base == 0 && power == 0)
    {   
        cout<<"Here\n";
        return INTAL("Not a number");
    }
    if(power == 0)
    {
        return INTAL(1);
    }
    if(power == 1)
    {
        return base;
    }
    INTAL squared = nth_power(base*base,power>>1);
    if(power & 1)
    {
        return base*squared;
    }
    else
    {
        return squared;
    }
}