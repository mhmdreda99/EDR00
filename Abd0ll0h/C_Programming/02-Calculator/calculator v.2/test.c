/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    char temptext[10];
    char sign[10];
    int i=0,num,result=0;
    int count=0;

    printf("\n\n\n\t\t\t\t\t\t calculator");
    printf("\nnotes:\n1.Numbers should be < 10 digits.");
    printf("\n2.Only operations allowed are:+ - * /.");
    printf("\n2.Only 5 operations allowed.");
    printf("\n\nEnter equation:");

    //temptext=;
    //num=atio(temptext);

    while (count <3)
    {
        for (i=0; i<10; i++)
        {
            //user enter the number and it'll be stored as string
            temptext[i]=getche();
            //the number entry process will end either entering a sign or using Enter key
            if ((temptext[i] == '+') || (temptext[i] == '-') || (temptext[i] == '*') || (temptext[i] == '/'))
            {
                goto sign;
            }
            if (temptext[i] == 13)
            {
                break;
            }
        }
        num= atoi(temptext);
        //printf("\nnumber=%d\n",num);
        sign[i]=temptext[i];
        if (count <1)
        {
            result=num;
        }
        else
        {
            switch (sign[i-1])
            {
            case '+' :
                result+=num;

                break;

            case '-' :
                result-=num;

                break;

            case '*' :
                //if (count == 0)
                //{
                //    result=1;
                //}
                result*=num;

                break;

            case '/' :
                //if (count == 0)
                //{
                //    result=1;
                //}
                result/=num;

                break;
            }
        }
        count++;
    }
end:
    printf("\n=%d",result);

}
/*struct SEquation
{
    int num[10];
    char sign;
};

struct SEquation exp[10];
int main()
{
    printf("\n\n\n\t\t\t\t\t\t calculator");
    printf("\nnotes:\n1.Numbers should be <= 10 digits.");
    printf("\n2.Only operations allowed are:+ - * /.");
    printf("\n2.Only 10 operations allowed.");
    printf("\n\nEnter equation:");

    char temptext[10];

    for (i=0; i<10; i++)
    {

    }

    for (i=0; i<10; i++)
        {
            temptext[i]=getche();
            if ((temptext[i] == '+') || (temptext[i] == '-') || (temptext[i] == '*') || (temptext[i] == '/'))
            {
                break;
            }
            //if (temptext[i] == 13)
            //{
            //    break;
            //}
        }

        num= atoi(temptext);
        sign[i]=temptext[i];
}*/
