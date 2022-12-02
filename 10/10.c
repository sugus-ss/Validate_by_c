/*10.c*/
/*This program check validation hotel services code.*/
/*Pornsawalee Kanjanatiti Gus 63070503467 20 June 2021*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkNumberCharacter(char hotelCode[]);
int checkDollar(char hotelCode[]);
int checkAllowCharacter(char hotelCode[]);
int checkUpperCharacter(char hotelCode[]);
int checkSpace(char hotelCode[]);

int main()
{
    char input[64];
    char hotelCode[64];
    int result=1;

    printf("Validate Hotel services code\n");
    printf("\tEnter hotel services code: ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%[^\n]",hotelCode);
    while(strlen(hotelCode) != 0 )
    {
        if(result != 0)
        {
            result=checkSpace(hotelCode);
            if(result != 0)
            {
                result=checkNumberCharacter(hotelCode);
            }
                if(result != 0)
                {
                    result=checkDollar(hotelCode);
                }
                    if(result != 0)
                    {
                        result=checkUpperCharacter(hotelCode);
                    }
                        if(result != 0)
                        {
                            result=checkAllowCharacter(hotelCode);
                        }
                            if(result != 0)
                            {
                                printf("Valid\n");
                            }
        }
        result=1;
        strcpy(hotelCode,"");
        printf("\tEnter hotel services code: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",hotelCode);
    }


}

int checkNumberCharacter(char hotelCode[])
{
    int i=0;
    int countP=0;
    int countR=0;
    int countW=0;
    int countS=0;
    int countT=0;
    int result=1;

    for(i=0 ; i<strlen(hotelCode) ; i++)
    {
        if(hotelCode[i]=='P')
        {
            countP++;
        }
        else if(hotelCode[i]=='R')
        {
            countR++;
        }
        else if(hotelCode[i]=='W')
        {
            countW++;
        }
        else if(hotelCode[i]=='S')
        {
            countS++;
        }
        else if(hotelCode[i]=='T')
        {
            countT++;
        }
    }
    if(countP>1)
    {
        printf("Invalid - P is repeated\n");
        result=0;
    }
    else if(countR>1)
    {
        printf("Invalid - R is repeated\n");
        result=0;

    }
    else if(countW>1)
    {
        printf("Invalid - W is repeated\n");
        result=0;

    }
    else if(countS>1)
    {
        printf("Invalid - S is repeated\n");
        result=0;

    }
    else if(countT>1)
    {
        printf("Invalid - T is repeated\n");
        result=0;
    }
    return result;
}

int checkDollar(char hotelCode[])
{
    int i=0;
    int countDollar=0;
    int result=1;

    for(i=0 ; i<strlen(hotelCode) ; i++)
    {
        if(hotelCode[i] == '$')
        {
            countDollar++;
        }
    }
    if(countDollar == 0)
    {
        printf("Invalid - no dollar sign\n");
        result=0;
    }
    else if(countDollar>4)
    {
        printf("Invalid - dollar sign\n");
        result=0;
    }
    return result;
}

int checkAllowCharacter(char hotelCode[])
{
    int i=0;
    int result=1;

    for(i=0 ; i<strlen(hotelCode) ; i++)
    {
        if(hotelCode[i] == 'P' || hotelCode[i] =='R' || hotelCode[i] =='W'
           || hotelCode[i] =='S' || hotelCode[i] =='T' || hotelCode[i] == '$')
        {
            result=1;
        }
        else
        {
            result=0;
            break;
        }
    }
    if(result == 0)
    {
        printf("Invalid - has character that is not allowed\n");
    }
    return result;
}

int checkUpperCharacter(char hotelCode[])
{
    int i=0;
    int result=1;

    for(i=0 ; i<strlen(hotelCode) ; i++)
    {
        if(hotelCode[i] == '$')
        {
            result=1;
        }
        else if(!isupper(hotelCode[i]))
        {
            printf("Invalid - lower case\n");
            result=0;
            break;
        }
    }
    return result;
}

int checkSpace(char hotelCode[])
{
    int i=0;
    int result=1;

    for(i=0 ; i<strlen(hotelCode) ; i++)
    {
        if(isspace(hotelCode[i]) != 0)
        {
            printf("Invalid - embedded spaces\n");
            result=0;
            break;
        }
    }
    return result;
}
