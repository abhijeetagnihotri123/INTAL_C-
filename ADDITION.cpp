#include "ADDITION.h"



string ADDITION::add_number(string number1,string number2)
{   
    APPEND_ZERO::reverse(number1);
    APPEND_ZERO::reverse(number2);
    int length_difference = number1.length()-number2.length();
    if(number1.length() < number2.length())
    {   
        length_difference = -length_difference;
        APPEND_ZERO::append_zero(number1,length_difference);
    }
    else
    {
        APPEND_ZERO::append_zero(number2,length_difference);
    }
    int number_length = number1.length();
    int carry = 0;
    int digit_sum;
    int i = 0;
    while(i < number_length)
    {
        digit_sum = int(number1[i]-'0')+int(number2[i]-'0')+carry;
        number1[i] = char((digit_sum%10)+'0');
        carry = digit_sum/10;
        i++;
    }
    if(carry > 0)
    {
        number1.push_back(char(carry+'0'));
    }
    reverse(number1);
    return number1;
}

