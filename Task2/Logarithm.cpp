#include "Logarithm.h"

int Logarithm(int number)
{
    if (number < 1)
    {
        return -2;
    }

    int exponent = 0;

    while (number % 2 == 0)
    {
        number /= 2;
        exponent++;
    }

    return (number == 1) ? exponent : -1;
}