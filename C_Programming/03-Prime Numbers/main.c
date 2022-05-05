#include <stdio.h>
#include <stdlib.h>
#include "STD_MACROS.h"
#include "STD_TYPES.h"
uint8 checkIfPrime_1(uint16 number);
uint8 checkIfPrime_2(uint16 number);




uint16 gprimeArray[1000],gprimeCounter,gflag=0;
int main()
{
    uint16 i,number,check;

    number=2;
    gprimeArray[0]=2;
    gprimeCounter=0;

    while (number < 1000)
    {
        check=checkIfPrime_1(number);
        number ++;
    }


    for (i=0; i<=gprimeCounter; i++)
    {
        printf("prime number[%d]=%d\n",i+1,gprimeArray[i]);
    }
}

uint8 checkIfPrime_1(uint16 number)
{
    uint16 i;
    gflag=1;
    for (i=number-1; i>1; i--)
    {
        if (number%i == 0)
        {
            return 0;
        }
    }
    gprimeArray[gprimeCounter]=number;
    gprimeCounter++;
    return 1;
}

uint8 checkIfPrime_2(uint16 number)
{
    uint16 i;
    for (i=0; i<=gprimeCounter; i++)
    {
        if (number%gprimeArray[i] == 0)
        {
            return 0;
        }
    }
    gprimeCounter++;
    gprimeArray[gprimeCounter]=number;
    return 1;
}

void printPrimeArray()
{

}
