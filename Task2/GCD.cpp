#include "GCD.h"

int RecursiveGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return RecursiveGCD(b, a % b);
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}