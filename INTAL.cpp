#include "INTAL.h"

INTAL::INTAL(string number)
{
    this->number = number;
}
INTAL::INTAL()
    :INTAL{"0"}
{
}
ostream &operator<<(ostream &os,INTAL &rhs)
{
    os<<rhs.number;
    return os;
}
istream &operator>>(istream &in,INTAL &rhs)
{
    string buff;
    in>>buff;
    rhs = INTAL(buff);
    return in;
}
INTAL& INTAL::operator=(const INTAL &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    this->number = rhs.number;
    return *this;
}
INTAL INTAL::operator+(const INTAL &rhs)
{
    string res = add_number(this->number,rhs.number);
    return INTAL(res);
}
INTAL INTAL::operator-(const INTAL &rhs)
{
    string res = subtract_number(this->number,rhs.number);
    return INTAL(res);
}
INTAL INTAL::operator*(const INTAL &rhs)
{
    string res = multiply(this->number,rhs.number);
    return INTAL(res);
}