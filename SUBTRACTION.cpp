#include "SUBTRACTION.h"


string SUBTRACTION::subtract_number_aux(string str1,string str2)
{   
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
 
    APPEND_ZERO::reverse(str1);
    APPEND_ZERO::reverse(str2);
 
    int carry = 0;
    for (int i = 0; i < n2; i++) {
 
        int sub
            = ((str1[i] - '0')
               - (str2[i] - '0')
               - carry);
 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
    APPEND_ZERO::reverse(str);
    return APPEND_ZERO::removeLeadingZeros(str);
}
string SUBTRACTION::subtract_number(string number1,string number2)
{   
    int diff_length;
    int comp_code = LEXICOGRAPHICAL::compare_numbers(number1,number2,diff_length);
    string result = "";
    if(comp_code == 0)
    {
        result = "0";
    }
    else if(comp_code == -1)
    {
        string temp = number1;
        number1 = number2;
        number2 = temp;
        result = result + '-';
    }
    result = result + subtract_number_aux(number1,number2);
    return result;
}


