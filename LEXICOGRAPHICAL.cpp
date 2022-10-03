#include "LEXICOGRAPHICAL.h"
#include <iostream>
using namespace std;
int LEXICOGRAPHICAL::compare_numbers(string number1,string number2,int &d)
{
    int comp_code = -1;
    int num1_digits = number1.length();
    int num2_digits = number2.length();
    d = num1_digits-num2_digits;
    if(num1_digits > num2_digits)
    {
        comp_code = 1;
    }
    else if(num1_digits < num2_digits)
    {   
        d = -d;
        comp_code = -1;
    }
    else
    {   
        int num_same_digits = 0;
        comp_code = 1;
        for(int i=0;i<num1_digits;i++)
        {
            if(number1[i] == number2[i])
            {
                num_same_digits++;
            }
            else
            {
                if(number1[i] < number2[i])
                {
                    comp_code = -1;
                }
                break;
            }
        }
        if(num_same_digits == num1_digits)
        {
            comp_code = 0;
        }
    }
    return comp_code;
}