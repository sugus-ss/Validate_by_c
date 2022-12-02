/*7.c*/
/*This program check validation international phone number*/
/*Pornsawalee Gus 63070503467 11 June 2021*/.
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkAllDigits(char phone[]);
int checkAllLength(char front[], char middle[], char last[]);
int checkAllDashes(char phone[]);


int main()
{
    char input[64];
    char phone[64];
    char front[32];
    char middle[32];
    char last[32];
    int result=1;


    printf("Validate international phone number\n");
    printf("\tEnter phone number: ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%[^\n]",phone);
    sscanf(phone,"+%[^-]-%[^-]-%[^\n]",front,middle,last);

    while(strlen(phone) != 0)
    {
        if(strlen(phone) != 0)
        {
            if(phone[0] != '+')
            {
                printf("Invalid - no plus\n");
                result = 0;
            }
            else
            {

                result = checkAllDigits(phone);
                if(result != 0)
                {
                    result = checkAllDashes(phone);
                    if(result != 0)
                    {
                        result = checkAllLength(front,middle,last);
                    }
                }
            }
        }
        if(result != 0)
        {
            printf("Valid\n");
        }
        strcpy(phone,"");
        printf("Enter phone number: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",phone);
        sscanf(phone,"+%[^-]-%[^-]-%[^\n]",front,middle,last);

    }
}

int checkAllDigits(char phone[])
{
    int i=1;
    int result=1;

    for(i=1 ; i<strlen(phone) ; i++)
    {
        if(!isdigit(phone[i]))
        {
            result=0;
        }
        if(phone[i] == '-')
        {
            result=1;
        }
    }
    if(result == 0)
    {
        printf("Invalid - illegal character\n");
    }

    return result;
}

int checkAllLength(char front[], char middle[], char last[])
{
    int result=1;

    if(strlen(front) > 3)
    {
        printf("Invalid - country code too long\n");
        result=0;
    }
    else if(strlen(front) < 1)
    {
        printf("Invalid - country code too short\n");
        result=0;
    }
    if(strlen(middle) > 3)
    {
        printf("Invalid - city/area code too long\n");
        result=0;
    }
    else if(strlen(middle) < 1)
    {
        printf("Invalid - city/area code too short\n");
        result=0;
    }
        if(strlen(last) > 10)
    {
        printf("Invalid - additional digits too long\n");
        result=0;
    }
    else if(strlen(last) < 6)
    {
        printf("Invalid - additional digits too short\n");
        result=0;
    }
    return result;
}

int checkAllDashes(char phone[])
{
    int i=0;
    int result=1;
    int dashes=0;

    for(i=0 ; i<strlen(phone) ; i++)
    {
        if(phone[i] == '-')
        {
            dashes++;
        }
    }
    if(dashes != 2)
    {
        printf("Invalid - missing dash\n");
        result = 0;
    }
    return result;
}

