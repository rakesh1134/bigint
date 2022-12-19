#include "BigInt.h"

int main()
{
    BigInt b5("123456789123456789");
    BigInt b6("123456789123456789");
    BigInt b7 = b5 * b6;
    cout<<b7;
    return 0;
}