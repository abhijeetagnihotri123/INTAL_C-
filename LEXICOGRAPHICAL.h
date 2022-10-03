#ifndef _LEXICOGRAPHICAL_H_
#define _LEXICOGRAPHICAL_H_
#include <string>
using namespace std;

class LEXICOGRAPHICAL
{
    public:
        LEXICOGRAPHICAL() = default;
        int compare_numbers(string,string,int&);
        virtual ~LEXICOGRAPHICAL() = default;
};

#endif