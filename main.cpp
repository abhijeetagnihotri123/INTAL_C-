#include "FIBONACI.h"
using namespace std;

int main()
{   
    cout<<"Enter which fibonacci number you want to find\n";
    int n;
    cin>>n;
    FIBONACI f;
    INTAL result = f.nth_fibonacci(n);
    cout<<result<<endl;
    return 0;
}