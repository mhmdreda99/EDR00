#include <stdio.h>


int main()
{
    char operation;
    int first, second, result, i=1;

    printf( "inter the operation :");
    scanf ("%c",&operation);

    switch (operation)
    {

    case '+' :
        printf( "The first & second number is: ");
        scanf ("%i%i",&first,&second);

        result= first + second ;
        printf( " %i",result);

        break;

    case '-' :
        printf( "The first number is:");
        scanf ("%i",&first);

        printf( "The second number is:");
        scanf ("%i",&second);

        result= first - second ;
        printf( " %i",result);

        break;

    case '*' :
        printf( "The first number is:");
        scanf ("%i",&first);

        printf( "The second number is:");
        scanf ("%i",&second);

        result= first * second ;
        printf( " %i",result);

        break;

    case '/' :
        printf( "The first number is: ");
        scanf ("%i",&first);

        printf( "The second number is: ");
        scanf ("%i",&second);

        result= first / second ;
        printf( " %i",result);

        break;

    case '%' :
        printf( "The first number is: ");
        scanf ("%i",&first);

        printf( "The second number is: ");
        scanf ("%i",&second);

        result= first%second ;
        printf( " %i",result);

        break;


    case '^' :
        printf( "The first number is: ");
        scanf ("%i",&first);

        printf( "The power number is: ");
        scanf ("%i",&second);

        result= pow(first,second) ;
        printf( " %i",result);

        break;

    case '!' :
        printf( "The number is: ");
        scanf ("%i",&first);
        result=1;

        for (i=1 ;i<= first ; i++)
        {
            result*=i ;
        }
            printf("%i",result);

        break;
    }
    return 0 ;
}
