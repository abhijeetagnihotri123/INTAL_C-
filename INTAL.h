#ifndef _INTAL_H_
#define _INTAL_H_
#include "MULTIPLICATION.h"
#include "SUBTRACTION.h"
using namespace std;

class INTAL:public MULTIPLICATION,public SUBTRACTION
{   
    friend ostream &operator<<(ostream &,INTAL &);
    friend istream &operator>>(istream &,INTAL &);
    private:
        string number;
    public:
        INTAL(void);
        INTAL(string);
        INTAL(long long int);
        string integer_to_string(long long int);
        INTAL &operator=(const INTAL&);
        INTAL &operator=(string);
        INTAL &operator=(long long int);
        string ADD_WITH_SIGN(string,string);
        string SUBTRACT_WITH_SIGN(string,string);
        string MULTIPLY_WITH_SIGN(string,string); 
        bool same_sign(string,string);
        INTAL operator+(const INTAL&);
        INTAL operator+(string);
        INTAL operator+(long long int);
        INTAL operator-(const INTAL&);
        INTAL operator-(string);
        INTAL operator-(long long int);
        INTAL operator*(const INTAL&);
        INTAL operator*(string);
        INTAL operator*(long long int);
        bool operator==(const INTAL&);
        bool operator==(string);
        bool operator==(long long int);
        bool operator<(const INTAL&);
        bool operator<(string);
        bool operator<(long long int);
        bool operator>(const INTAL&);
        bool operator>(string);
        bool operator>(long long int);
        virtual ~INTAL(void) = default;
};

#endif