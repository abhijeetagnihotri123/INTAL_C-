#include "FIBONACI.h"
#include "FACTORIAL.h"
#include "POWER.h"
#include <assert.h>
using namespace std;

int main()
{       
    FIBONACI fib;
    INTAL result;
    result = fib.nth_fibonacci(6);
    assert(result == 8);
    result = fib.nth_fibonacci(54);
    assert(result == 86267571272);
    
    POWER p;
    INTAL base = 132;
    int power = 22;
    result = p.nth_power(base,power);
    assert(result == "44939318957927209828573323731157595428879335424"); //Power tesst_case
    result = p.nth_power(base,132);
    assert(result == "8236807553829350461756420932598674082378771394930288750437445109544512473262629747478916358110666874529869907667598064813004239745475675541595182998125748275083389010574180171062415253377526018038346255731720088950321363742685757684023516961703222536841514966773464808765654040576");
    result = p.nth_power(base,3);
    assert(result == 2299968);// variation that INTAL_C supports interger for small numbers and strings for very large computations
    
    FACTORIAL fact;
    result = fact.nth_factorial(25);
    assert(result == "15511210043330985984000000");
    result = fact.nth_factorial(100);
    assert(result == "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
    cout<<"All test cases passed\n";
    return 0;
}