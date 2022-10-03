#include "MULTIPLICATION.h"
string MULTIPLICATION::removeLeadingZeros(string str)
{
    int i = 0;
    while(i < str.length() && str[i] == '0')
    {
        i++;
    }
    string s = "";
    while(i < str.length())
    {
        s = s + str[i];
        i++;
    }
    return s;
}
string MULTIPLICATION::multiply_aux(string A,string B)
{
    if (A.length() > B.length())
    {
        string temp = A;
        A = B;
        B = temp;
    }
    int n1 = A.length(), n2 = B.length();
    while (n2 > n1) {
        A = "0" + A;
        n1++;
    }
    if (n1 == 1) 
    {
        int ans = stoi(A) * stoi(B);
        return to_string(ans);
    }
    if (n1 % 2 == 1) 
    {
        n1++;
        A = "0" + A;
        B = "0" + B;
    }
    string Al, Ar, Bl, Br;
    for (int i = 0; i < n1 / 2; ++i) 
    {
        Al += A[i];
        Bl += B[i];
        Ar += A[n1 / 2 + i];
        Br += B[n1 / 2 + i];
    }
    string p = multiply(Al, Bl);
    string q = multiply(Ar, Br);
    string r = SUBTRACTION::subtract_number(
        multiply(ADDITION::add_number(Al, Ar),
                 ADDITION::add_number(Bl, Br)),
        ADDITION::add_number(p, q));
    for (int i = 0; i < n1; ++i)
        p = p + "0";
    
    for (int i = 0; i < n1 / 2; ++i)
        r = r + "0";
 
    string ans = ADDITION::add_number(p, ADDITION::add_number(q, r));
 
    ans = removeLeadingZeros(ans);
 
    return ans;
}
string MULTIPLICATION::multiply(string number1,string number2)
{
    return multiply_aux(number1,number2);
}
// int main()
// {   
//     MULTIPLICATION mul;
//     return 0;
// }