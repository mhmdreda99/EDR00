#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddStudent();
void ViewStudents();
void DeleteStudent();
void DeleteAllStudent();

struct SStudent
{
    int ID;
    char firstName[15];
    char lastName[15];
    char gpa[5];
};

struct SStudent gstudent[1000];
int gcount=0;

void main()
{
    while(1)
    {
        printf("\n\n\t\t\t\t\tStudent Record System\n");
        printf("\n'a' add new student\n'd' delete existing student\n'v' list all students\n");
        printf("'D' Delete all Student\n");
        printf("\nselect an option:");

        switch(getche())
        {
        case 'a':
            system("cls");
            printf("\n\n\t\t\t\t\t  Add Students");
            AddStudent();
            break;
        case 'v':
            system("cls");
            printf("\n\n\n\t\t\t\t\t  Students List");
            ViewStudents();
            break;
        case 'd':
            system("cls");
            printf("\n\n\n\t\t\t\t\t  Delete Students");
            DeleteStudent();
            break;
        case 'D':
            system("cls");
            printf("\n\n\n\t\t\t\t\t  Delete All Students");
            printf("are you sure? y/n");
            if (getch() == 'y');
            {
                DeleteAllStudent();
            }
            break;
        default:
            printf("\nEnter only selection listed.");
        }

        puts("\nPress 'e' to exit program or any key for another action.");
        if (getch() == 'e')
        {
            exit(0);
        }
        system("cls");
    }
}

void AddStudent()
{
    int x;
    char repeat;

    do
    {
        x=0;
        gstudent[gcount].ID=gcount+1;
        printf("\n\nID: %d\n",gstudent[gcount].ID);
        printf("Student First name:");
        scanf(" %s",gstudent[gcount].firstName);
        if ('gstudent[gcount].firstName' == 'a')
        {
            printf("Student First name:");
            scanf(" %s",gstudent[gcount].firstName);
        }
        printf("\nStudent Last name:");
        scanf(" %s",gstudent[gcount].lastName);
        printf("\nStudent GPA:");
        scanf(" %s",gstudent[gcount].gpa);
        gcount++;
        printf("\nto add another student data enter 'c', for a new action enter any key:");
        if (getche() == 'c')
        {
            x=1;
        }
    }
    while (x == 1);
}


void ViewStudents()
{
    if (gcount<1)
    {
        printf("\n\nNo data is listed.\n");

    }
    else
    {
        int j;
        if(gcount<1)printf("\nEmpty list.\n");
        for(j=0; j<gcount; j++)
        {
            printf(" \nID: %d\n", gstudent[j].ID);
            printf(" Student Name: %s %s\n", gstudent[j].firstName,gstudent[j].lastName);
            printf(" GPA: %s\n", gstudent[j].gpa);
        }
    }
}


void DeleteStudent()
{
    char repeat;
    int ID,i,j,flag=0;
    //int start=0, end=gcount, middle;
    if (gcount<1)
    {
        printf("\n\nNo data is listed.\n");

    }
    else
    {

        printf("\n\nEnter Student ID:");
        scanf("%d",&ID);

        ///Binary Search
        /*while(start <= end)
        {
            middle=(start+end)/2;
            if (ID == gstudent[middle].ID)
            {
                flag=1;
                printf("\nThe student data to be deleted.");
                printf(" \nID: %d\n", gstudent[middle].ID);
                printf(" Student Name: %s %s\n", gstudent[middle].firstName,gstudent[middle].lastName);
                printf(" GPA: %s\n", gstudent[middle].gpa);
                for (i=ID; i<gcount; i++)
                {
                    gstudent[i].ID=gstudent[i+1].ID;
                    gstudent[i].firstName=gstudent[i+1].firstName;
                    gstudent[i].lastName=gstudent[i+1].lastName;
                    gstudent[i].gpa=gstudent[i+1].gpa;
                }
                gcount--;

            }
            else if (ID > gstudent[middle].ID)
            {
                start=middle+1;
            }
            else if (ID < gstudent[middle].ID)
            {
                end=middle-1;
            }
        }*/
        for(i=0; i<gcount; i++)
        {
            if(gstudent[i].ID==ID)
            {
                flag=1;
                for (j=i; j<gcount; j++)
                {
                    gstudent[j].ID=j+1;
                    strcpy(gstudent[j].firstName, gstudent[j+1].firstName);
                    //gstudent[j].firstName=gstudent[j+1].firstName;
                    strcpy(gstudent[j].lastName, gstudent[j+1].lastName);
                    //gstudent[j].lastName=gstudent[j+1].lastName;
                    strcpy(gstudent[j].gpa, gstudent[j+1].gpa);
                    //gstudent[j].gpa=gstudent[j+1].gpa;
                }

                /*gstudent[gcount-1].ID=0;
                strcpy(gstudent[gcount-1].firstName,0);
                strcpy(gstudent[gcount-1].lastName,0);
                strcpy(gstudent[gcount-1].gpa,0);*/
                gcount--;
                return;
            }
        }

        if (flag==0)
        {
            printf("Element %d is not found.\n",ID);
            return;
        }

        ///
        /*printf("Enter e to exit, any key to continue:");
        scanf(" %c",&repeat);
        system("cls");*/
    }
}


void DeleteAllStudent()
{
    int i;
    for (i=0; i<gcount; i++)
    {
        gstudent[i].ID=0;
        strcpy(gstudent[i].firstName,0);
        strcpy(gstudent[i].lastName,0);
        strcpy(gstudent[i].gpa,0);
    }
    gcount=0;
}

