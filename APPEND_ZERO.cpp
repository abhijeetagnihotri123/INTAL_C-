#include "APPEND_ZERO.h"
void APPEND_ZERO::reverse(string &s)
{ 
    int n = s.length();
    int m = n>>1;
    int i = 0;
    while(i < m)
    {
        swap(s[i],s[n-i-1]);
        i++;
    }
}
string APPEND_ZERO::removeLeadingZeros(string str)
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
void APPEND_ZERO::append_zero(string &s,int d)
{
    while(d--)
    {
        s.push_back('0');
    }
}