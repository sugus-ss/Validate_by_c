/*13.c*/
/*This program check validation street address in Bangkok(simplified).*/
/*Pornsawalee Kanjanatiti Gus 63070503467 21 June 2021*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkHouseNumber(char houseNumber[]);
int checkPostalCode(char postalCode[]);

int main()
{
    char input[32];
    char address[32];
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int countSpace = 0;
    int indexhouseNumber=0;
    int indexStreet=0;
    int indexPostalCode=0;
    char houseNumber[32] = "";
    char street[32] = "";
    char label[32] = "";
    char postalCode[32] = "";
    int result=1;

    printf("Validate street address in Bangkok\n");
    printf("\tEnter street address in Bangkok: ");
    memset(input,0,sizeof(input));
    memset(address,0,sizeof(address));
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%[^\n]",address);
    while(strlen(address) != 0)
    {
        for(i=0 ; i<strlen(address) ; i++)
        {
            if(address[i] == ' ')
            {
                countSpace++;
                if(countSpace == 1)
                {
                    indexhouseNumber = i;
                }
                if(countSpace == 2)
                {
                    indexStreet = i;
                    indexPostalCode = i;
                }
                if(countSpace == 3)
                {
                    indexPostalCode = i;
                }
            }
        }
        for(i=0 ; i<indexhouseNumber ; i++)
        {
            houseNumber[i] = address[i];
        }
        for(i=indexhouseNumber+1 ; i<indexPostalCode ; i++)
        {
            street[j] = address[i];
            j++;
        }
        if(countSpace == 3)
        {
            for(i=indexStreet+1 ; i<indexPostalCode ; i++)
            {
                label[k] = address[i];
                k++;
            }
        }
        for(i=indexPostalCode+1 ; i<strlen(address) ; i++)
        {
            postalCode[l] = address[i];
            l++;
        }
        result = checkHouseNumber(houseNumber);
        if(result !=0)
        {
            result = checkPostalCode(postalCode);
            if(result != 0)
            {
                printf("Valid\n");
            }
        }
        result=1;
        countSpace = 0;
        memset(input,0,sizeof(input));
        memset(address,0,sizeof(address));
        memset(houseNumber,0,sizeof(houseNumber));
        memset(street,0,sizeof(street));
        memset(label,0,sizeof(label));
        memset(postalCode,0,sizeof(postalCode));
        j=0;
        k=0;
        l=0;
        /*strcpy(address,"");
        strcpy(houseNumber,"");
        strcpy(street,"");
        strcpy(label,"");
        strcpy(postalCode,"");*/
        printf("\tEnter street address in Bangkok: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",address);
    }
}

int checkHouseNumber(char houseNumber[])
{
    int i=0;
    int j=0;
    int slash=0;
    int result=1;
    int indexslash=-1;

    if(!isdigit(houseNumber[0]))
    {
        printf("Invalid - illegal house number\n");
        result=0;
    }
    if(result == 1)
    {
        for(i=0 ; i<strlen(houseNumber) ; i++)
        {
            if(!isdigit(houseNumber[i]))
            {
                if(houseNumber[i] != '/')
                {
                printf("Invalid - alphabet in the number\n");
                result=0;
                break;
                }
            }
            if(houseNumber[i] == '/')
            {
                slash++;
                indexslash = i;
                if(slash>1)
                {
                    printf("Invalid - must have 1 slash\n");
                    result=0;
                    break;
                }
            }
            if(indexslash != -1)
            {
                if(!isdigit(houseNumber[indexslash+1]) || !isdigit(houseNumber[indexslash-1]))
                {
                    printf("Invalid - number starts with/\n");
                    result = 0;
                }
            }
        }
    }
    return result;
}

int checkPostalCode(char postalCode[])
{
    int result=1;

    if(strlen(postalCode) != 5)
    {
        printf("Invalid - postal code must have 5 digits\n");
        result = 0;
    }
    else if(postalCode[0] != '1' || postalCode[1] != '0')
    {
        printf("Invalid - postal code must begin with 10\n");
        result = 0;
    }
    return result;
}





