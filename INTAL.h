#ifndef _INTAL_H_
#define _INTAL_H_
#include "MULTIPLICATION.h"
using namespace std;

class INTAL:public MULTIPLICATION
{   
    friend ostream &operator<<(ostream &,INTAL &);
    friend istream &operator>>(istream &,INTAL &);
    private:
        string number;
    public:
        INTAL(void);
        INTAL(string);
        INTAL &operator=(const INTAL&);
        INTAL operator+(const INTAL&);
        INTAL operator-(const INTAL&);
        INTAL operator*(const INTAL&);
        virtual ~INTAL(void) = default;
};

#endif