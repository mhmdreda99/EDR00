#include <stdio.h>
void Dec_Bi();
void Dec_Oct();
void Dec_Hex();

int main ()
{
    int num;

    while (1)
    {
        printf("\n\n\n\t\t\t\t\t\t\t Converter");
        printf("\nSelect Conversion type: ");
        printf("\n'b' convert Decimal to Binary.\n'o' convert Decimal to Octa.\n'h' convert Decimal to Hexa.\n");
        printf("Select Conversion type: ");
        switch (getche())
        {
        case 'b':
            Dec_Bi();
            break;
        case 'o':
            Dec_Oct();
            break;
        case 'h':
            Dec_Hex();
            break;
        default:
            printf("\nInvalid Selection.\n");
        }
        getch();
        system("cls");
    }

}
///convert Decimal to Binary
void Dec_Bi()
{
    int num;
    int bi[40];
    int i,j;

    printf("\n\n\t\t\t\t\t\tDecimal to Binary Converter");
    printf("\nDecimal=");
    scanf("%d",&num);
    i=0;

    while (num >= 1)
    {

        if ((num%2) == 0)
        {
            bi[i]=0;
        }
        else
        {
            bi[i]=1;
        }
        i++;
        num/=2.0;
    }

    printf("Binary=");
    for (j=(i-1); j>=0; j--)
    {
        printf("%d",bi[j]);
    }
}

///convert Decimal to Octa
void Dec_Oct()
{
    int num,iNum;
    int oct[40];
    int i,j;
    float fNum;

    printf("\n\n\t\t\t\t\t\tDecimal to Octa Converter");
    printf("\nDecimal=");
    scanf("%d",&num);
    i=0;

    while (num >9)
    {
        fNum=num/8.0;
        num=fNum;
        oct[i]=(fNum-num)*8;
        i++;
    }
    oct[i]=num;
    printf("Octa=");
    for (j=(i); j>=0; j--)
    {
        printf("%d",oct[j]);
    }
}

///convert Decimal to Hexa
void Dec_Hex()
{
    int num,nNum;
    int hex[40];
    int i,j;
    float fNum;

    printf("\n\n\t\t\t\t\t\tDecimal to Hexa Converter");
    printf("\nDecimal=");
    scanf("%d",&num);
    i=0;

    while (num >15)
    {
        fNum=num/16.0;
        num=fNum;
        nNum=(fNum-num)*16;
        hex[i]=nNum;
        i++;
    }
    hex[i]=num;

    printf("Hexa=");
    for (j=(i); j>=0; j--)
    {
        if ((hex[j]>9) && (hex[j]<16))
        {
            if (hex[j] == 10)
            {
                printf("A");
            }
            else if (hex[j] == 11)
            {
                printf("B");
            }
            else if (hex[j] == 12)
            {
                printf("C");
            }
            else if (hex[j] == 13)
            {
                printf("D");
            }
            else if (hex[j] == 14)
            {
                printf("E");
            }
            else if (hex[j] == 15)
            {
                printf("F");
            }
        }
        else
        {
            printf("%d",hex[j]);
        }
    }
}



