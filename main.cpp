#include "ADDITION.h"
#include "SUBTRACTION.h"
#include "MULTIPLICATION.h"

using namespace std;

int main()
{   
    ADDITION add;
    SUBTRACTION sub;
    MULTIPLICATION mul;
    string number1,number2;
    cin>>number1>>number2;
    cout<<add.add_number(number1,number2)<<endl;
    cout<<sub.subtract_number(number1,number2)<<endl;
    cout<<mul.multiply(number1,number2)<<endl;
    return 0;
}