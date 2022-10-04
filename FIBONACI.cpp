#include "FIBONACI.h"

INTAL FIBONACI::nth_fibonacci(int n)
{
    INTAL f[n+1];
    INTAL F("1");
    f[1] = F;
    for(int i=2;i<=n;i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}