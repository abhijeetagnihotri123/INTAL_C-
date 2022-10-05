#include "INTAL.h"

INTAL::INTAL(string number)
{
    this->number = number;
}
INTAL::INTAL()
    :INTAL{"0"}
{
}
string INTAL::integer_to_string(long long int number)
{   
    string s = "";
    if(number == 0)
    {
        s = "0";
    }
    else
    {
        long long int number1 = number;
        if(number < 0)
        {
            number1 = -number1;
        }
        while(number1 > 0)
        {
            int a = number1%10;
            s = to_string(a) + s;
            number1 = number1/10;
        }
        if(number < 0)
        {
            s = "-"+s;
        }
    }
    return s;
}
INTAL::INTAL(long long int n)
    :INTAL{integer_to_string(n)}
{
}
bool INTAL::same_sign(string number1,string number2)
{
    bool b1 = ((number1[0]>='0' && number1[0]<='9') && (number2[0] >= '0' && number2[0] <= '9'));
    bool b2 = (number1[0] == '-' && number2[0] == '-');
    return (b1 || b2);
}
string INTAL::ADD_WITH_SIGN(string number1,string number2)
{
    if(same_sign(number1,number2))
    {
        if(number1[0] == '-')
        {
            number1 = add_number(number1.substr(1),number2.substr(1));
            number2 = "-";
            number2 = number2+number1;
            number1 = number2;
        }
        else
        {
            number1 = add_number(number1,number2);
        }
    }
    else
    {
        if(number1[0] == '-')
        {
            string temp = number1;
            number1 = number2;
            number2 = temp;
        }
        number1 = subtract_number(number1,number2.substr(1));
    }
    return number1;
}
string INTAL::SUBTRACT_WITH_SIGN(string number1,string number2)
{
    if(same_sign(number1,number2))
    {
        if(number1[0] == '-')
        {
            number1 = subtract_number(number1.substr(1),number2.substr(1));
        }
        else
        {
            number1 = subtract_number(number1,number2);    
        }
    }
    else
    {
        if(number1[0] == '-')
        {
            number1 = add_number(number1.substr(1),number2);
            number2 = "-"+number1;
            number1 = number2;
        }
        else
        {
            number1 = add_number(number1,number2.substr(1));
        }
    }
    return number1;
}
string INTAL::MULTIPLY_WITH_SIGN(string number1,string number2)
{
    if(same_sign(number1,number2))
    {
        if(number1[0] == '-')
        {
            number1 = multiply(number1.substr(1),number2.substr(1));
        }
        else
        {
            number1 = multiply(number1,number2);
        }
    }
    else
    {
        if(number1[0] == '-')
        {
            number2 = multiply(number1.substr(1),number2);
            number1 = "-"+number2;
        }
        else
        {
            number2 = multiply(number1,number2.substr(1));
            number1 = "-"+number2;
        }
    }
    return number1;
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
INTAL& INTAL::operator=(string number)
{
    this->number = number;
    return *this;
}
INTAL& INTAL::operator=(long long int number)
{
    this->number = integer_to_string(number);
    return *this;
}
INTAL INTAL::operator+(const INTAL &rhs)
{
    string res = ADD_WITH_SIGN(this->number,rhs.number);
    return INTAL(res);
}
INTAL INTAL::operator+(string number)
{
    string res = ADD_WITH_SIGN(this->number,number);
    return INTAL(res);
}
INTAL INTAL::operator+(long long int number)
{
    string res = ADD_WITH_SIGN(this->number,integer_to_string(number));
    return INTAL(res);
}
INTAL INTAL::operator-(const INTAL &rhs)
{
    string res = SUBTRACT_WITH_SIGN(this->number,rhs.number);
    return INTAL(res);
}
INTAL INTAL::operator-(string number)
{
    string res = SUBTRACT_WITH_SIGN(this->number,number);
    return INTAL(res);
}
INTAL INTAL::operator-(long long int number)
{
    string res = SUBTRACT_WITH_SIGN(this->number,integer_to_string(number));
    return INTAL(res);
}
INTAL INTAL::operator*(const INTAL &rhs)
{
    string res = MULTIPLY_WITH_SIGN(this->number,rhs.number);
    return INTAL(res);
}
INTAL INTAL::operator*(string number)
{
    string res = MULTIPLY_WITH_SIGN(this->number,number);
    return INTAL(res);
}
INTAL INTAL::operator*(long long int number)
{
    string res = MULTIPLY_WITH_SIGN(this->number,integer_to_string(number));
    return INTAL(res);
}
bool INTAL::operator==(const INTAL &rhs)
{   
    if(same_sign(this->number,rhs.number))
    {
        int d;
        string num1,num2;
        num1 = this->number;
        num2 = rhs.number;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 0);
    }
    return false;
}
bool INTAL::operator==(string number)
{
    if(same_sign(this->number,number))
    {
        int d;
        string num1,num2;
        num1 = this->number;
        num2 = number;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 0);
    }
    return false;
}
bool INTAL::operator==(long long int number)
{
    string num2 = integer_to_string(number);
    if(same_sign(this->number,num2))
    {
        int d;
        string num1 = this->number;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 0);
    }
    return false;
}
bool INTAL::operator<(const INTAL &rhs)
{
    string num1 = this->number;
    string num2 = rhs.number;
    if(same_sign(num1,num2))
    {   
        int d;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == -1);
    }
    else 
    {
        if(num1[0] == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool INTAL::operator<(string number)
{
    string num1,num2;
    num1 = this->number;
    num2 = number;
    if(same_sign(this->number,number))
    {
        int d;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == -1);
    }
    else
    {
        if(num1[0] == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
bool INTAL::operator<(long long int number)
{   
    string num1 = this->number;
    string num2 = integer_to_string(number);
    if(same_sign(this->number,num2))
    {
        int d;
        string num1 = this->number;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == -1);
    }
    else if(num1[0] == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool INTAL::operator>(const INTAL &rhs)
{
    string num1 = this->number;
    string num2 = rhs.number;
    if(same_sign(num1,num2))
    {   
        int d;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 1);
    }
    else 
    {
        if(num1[0] == '-')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool INTAL::operator>(string number)
{
    string num1,num2;
    num1 = this->number;
    num2 = number;
    if(same_sign(this->number,number))
    {
        int d;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 1);
    }
    else
    {
        if(num1[0] == '-')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool INTAL::operator>(long long int number)
{   
    string num1 = this->number;
    string num2 = integer_to_string(number);
    if(same_sign(this->number,num2))
    {
        int d;
        string num1 = this->number;
        if(num1[0] == '-')
        {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        return (LEXICOGRAPHICAL::compare_numbers(num1,num2,d) == 1);
    }
    else
    {
        if(num1[0] == '-')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}