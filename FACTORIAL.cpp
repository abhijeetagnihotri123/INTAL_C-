#include "FACTORIAL.h"

INTAL FACTORIAL::nth_factorial(int n)
{
    INTAL product;
    product = 1;
    
    for(int i=2;i<=n;i++)
    {   
        product = product * i;
    }
    return product;
}