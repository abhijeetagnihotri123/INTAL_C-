#include "MULTIPLICATION.h"

string MULTIPLICATION::multiply_with_single_digit(string number,char digit)
{
    int carry = 0;
    int num_length = number.length();
    int dig = int(digit-'0');
    int i = 0;
    while(i < num_length)
    {
        int mul = (int(number[i]-'0')*dig)+carry;
        carry = mul/10;
        char c = char((mul%10)+'0');
        number[i] = c;
        i++;
    }
    if(carry > 0)
    {   
        number = number + to_string(carry);
    }
    APPEND_ZERO::reverse(number);
    return number;
}
string MULTIPLICATION::multiply(string number1,string number2)
{   
    APPEND_ZERO::reverse(number1);
    APPEND_ZERO::reverse(number2);
    string carry = "0";
    int i = 0;
    int num_length = number1.length();
    while(i < num_length)
    {
        string multiplication = multiply_with_single_digit(number2,number1[i]);
        multiplication = add_number(multiplication,carry);
        APPEND_ZERO::reverse(multiplication);
        carry = multiplication.substr(1);
        APPEND_ZERO::reverse(carry);
        number1[i] = multiplication[0];
        i++;
    }
    APPEND_ZERO::reverse(carry);
    if(carry.length() > 0)
    {
        number1 = number1 + carry;
    }
    APPEND_ZERO::reverse(number1);
    return number1;
}