#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct SEquation
{
    float num;
    char sign;
};
struct SEquation op[10];


int main()
{
    int i,k,l,m;
    char temptext[10];
    int count=0;

    printf("\n\n\n\t\t\t\t\t\t calculator");
    printf("\nNotes:\n1.Numbers should be < 10 digits.");
    printf("\n2.Integer and Float numbers allowed.");
    printf("\n3.Only operations allowed are:+ - * /.");
    printf("\n4.Only 10 operations allowed.");
    //to change number of operation, two changes should be made:
    //1.change command L32 'while (count<x)', where x=(no. of operations+1).
    //2.change command L44 'if (count<y)', where y=(no. of operations).
    printf("\n\nEnter equation:");

    ///Storing Equation
    //note:the storing process is continued unless number of operation is violated.
    //or Enter key is pressed.
    while (count<11)
    {
        for (i=0; i<10; i++ )
        {
            //user enter the number and it'll be stored as string
            temptext[i]=getche();
            //each number storing process will end either by
            //1.entering a 'sign'(equation not finished)
            if ((temptext[i] == '+') || (temptext[i] == '-') ||(temptext[i] == '*') || (temptext[i] == '/'))
            {
                //the count of signs stored is less than count of numbers stored
                //this command to not store the sign after the 11th number if Entered
                if (count<10)
                {
                    //storing the sign
                    op[count].sign=temptext[i];
                }
                break;
            }
            //2.using 'Enter key'(at end of equation)
            else if (temptext[i] == 13)
            {
                //storing the number after being ended by 'Enter Key' way
                op[count].num=atof(temptext);
                count++;
                //after user enter 'Enter Key' the storing process will be ended
                goto endEquation;
            }
        }
        //storing the number after being ended by 'sign' way
        op[count].num=atof(temptext);
        count++;
    }
endEquation:

    //printing the numbers entered by user
    for (k=0; k<count; k++)
    {
        printf("\nnumber[%d]=%0.3f",k,op[k].num);
    }
    printf("\n");

    //printing how many operations will be executed
    printf("\nNo. of operations=%d",count-1);
    //printing Equation as indication for successful storing
    printf("\n\nEquation=");
    for (k=0; k<count; k++)
    {
        printf("%0.3f",op[k].num);
        printf("%c",op[k].sign);
    }
    printf("\n");
    ///Processing Equation
    //first multiplication and Division.
    for (k=0; k<count; k++)
    {
        //a linear search is supposed find either first '*' or '/'
        //and execute the operation between first operand (before sign)
        //and second operand (after sign)
        if ((op[k].sign == '*') || (op[k].sign == '/'))
        {

            switch(op[k].sign)
            {
            case '*':
                //store the result in the first operand.
                op[k].num=op[k].num*op[k+1].num;

                break;
            case '/':
                op[k].num=(op[k].num)/(op[k+1].num);
                break;
            }
            //remove the second operand and rewrite the numbers.
            for (l=k; l<count; l++)
            {
                op[l+1].num=op[l+2].num;
                op[l].sign=op[l+1].sign;
            }
            count--;
            k--;
        }
    }

    //print equation after multiplication and division
    ///printf("\t=");
    /*for (m=0; m<count; m++)
    {
        printf("%0.3f",op[m].num);
        printf("%c",op[m].sign);
    }*/

    //Summation and subtraction should be done second.
    for (k=0; k<count; k++)
    {
        k=0;
        //a linear search is supposed find either first '+' or '-'.
        //and execute the operation between first op (before sign) and second op (after sign).
        if ((op[k].sign == '+') || (op[k].sign == '-'))
        {
            switch(op[k].sign)
            {
            case '+':
                //store the result in the first operand
                op[k].num=op[k].num+op[k+1].num;

                break;
            case '-':
                op[k].num=(op[k].num)-(op[k+1].num);
                break;
            }
            //remove the second operand and rewrite the numbers
            for (l=k; l<count; l++)
            {
                op[l+1].num=op[l+2].num;
                op[l].sign=op[l+1].sign;
            }
            count--;
        }
    }

    //print equation after multiplication and division and Summation and subtraction
    printf("\t=");
    for (m=0; m<count; m++)
    {
        printf("%0.3f",op[m].num);
        printf("%c",op[m].sign);
    }
}
