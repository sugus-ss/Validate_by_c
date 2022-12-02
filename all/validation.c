/*validation.c*/
/*This program is to validate input means to check some data to make sure it
follows rules about its content and format*/
/*Pornsawalee Kanjanatiti Gus 63070503467 12 July 2021*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int checkValidaionDateAndTime();
int checkAllDigits_date_time(char date_time[]);
int checkFormat(char date_time[]);
int checkYearMonthDay(char year[],char month[],char day[]);
int checkTime(char hour[],char minute[]);
int checkDay(char year[],char month[],char day[]);

int checkValidationInternationalPhoneNumber();
int checkAllDigits(char phone[]);
int checkAllLength(char front[], char middle[], char last[]);
int checkAllDashes(char phone[]);

int checkValidationHotelServicesCode();
int checkNumberCharacter(char hotelCode[]);
int checkDollar(char hotelCode[]);
int checkAllowCharacter(char hotelCode[]);
int checkUpperCharacter(char hotelCode[]);
int checkSpace(char hotelCode[]);

int checkValidationStreetAddressInBangkok();
int checkHouseNumber(char houseNumber[]);
int checkPostalCode(char postalCode[]);

int main()
{
    char input[64];
    int choice=0;
    int i=0;
    int count[4]={0,0,0,0};

    while(choice != 5)
    {
        printf("\nValidation options:\n");
        printf("\t1 - Check date and time in form yyyy-mm-dd hh:tt\n");
        printf("\t2 - Check international phone number\n");
        printf("\t3 - Check hotel services code\n");
        printf("\t4 - Check street address in Bangkok\n");
        printf("\t5 - Exit the program\n");
        printf("What do you want to do? ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d",&choice);
        switch(choice)
        {
            case 1:
                count[0] = checkValidaionDateAndTime();
                break;
            case 2:
                count[1] = checkValidationInternationalPhoneNumber();
                break;
            case 3:
                count[2] = checkValidationHotelServicesCode();
                break;
            case 4:
                count[3] = checkValidationStreetAddressInBangkok();
                break;
            case 5:
                break;
            default:
            {
                printf("\nVaidation options must be 1-5");
            }
        }
    }
    printf("\nProgram run summary:");
    for(i=0 ; i<4 ;i++)
    {
        printf("\n\tVadation type %d:  %d",i+1,count[i]);
    }
}

int checkValidaionDateAndTime()
{
    char input[64];
    char date_time[64];
    int result=1;
    char year[32];
    char month[32];
    char day[32];
    char hour[32];
    char minute[32];
    int count=0;

    printf("\nValidate Western date and time in form yyyy-mm-dd hh:tt\n");
    printf("\tEnter your date and time ");
    fgets(date_time,sizeof(date_time),stdin);
    /*sscanf(input,"%s",date_time);*/
    sscanf(date_time,"%[^-]-%[^-]-%[^ ] %[^:]:%[^\n]",year,month,day,hour,minute);

    while(strlen(date_time)-1 != 0)
    {
        if(result != 0)
        {
            result=checkAllDigits_date_time(date_time);
            if(result != 0)
            {
                result=checkFormat(date_time);
                if(result != 0)
                {
                    result=checkYearMonthDay(year,month,day);
                    if(result != 0)
                    {
                        result=checkDay(year,month,day);
                    }
                        if(result != 0)
                        {
                            result=checkTime(hour,minute);
                        }
                }
            }
        }
        if(result != 0)
        {
            printf("Valid\n");
        }
        result=1;
        strcpy(date_time,"");
        count++;
        printf("\tEnter your date and time ");
        fgets(date_time,sizeof(date_time),stdin);
        sscanf(date_time,"%[^-]-%[^-]-%[^ ] %[^:]:%[^\n]",year,month,day,hour,minute);
    }
    return count;
}

int checkAllDigits_date_time(char date_time[])
{
    int i=0;
    int result=1;

    for(i=0 ; i<strlen(date_time) ; i++)
    {
        if(date_time[i] == '-' || date_time[i] == '\n' ||date_time[i] == ':' || date_time[i] == ' ')
        {
            result=1;
        }
        else if(!isdigit(date_time[i]))
        {
            result=0;
            break;
        }
    }
    if(result == 0)
    {
        printf("Invalid - illegal character\n");
    }
    return result;
}

int checkFormat(char date_time[])
{
    int result=1;

    if(strlen(date_time)-1 != 16)
    {
        printf("Invalid - illegal format\n");
        result=0;
    }
    else if(date_time[4] != '-' || date_time[7] != '-' || date_time[10] != ' ' || date_time[13] != ':')
    {
        printf("Invalid - wrong order of fields\n");
        result=0;
    }
    return result;
}

int checkYearMonthDay(char year[],char month[],char day[])
{
    int result=1;
    int number_year=0;
    int number_month=0;
    int number_day=0;

    number_year=atoi(year);
    number_month=atoi(month);
    number_day=atoi(day);

    if(number_year<1920 || number_year>2120)
    {
        printf("Invalid - illegal year\n");
        result=0;
    }
    else if(number_month<1 || number_month>12)
    {
        printf("Invalid - illegal month\n");
        result=0;
    }
    else if(number_day<1 || number_day>31)
    {
        printf("Invalid - illegal day\n");
        result=0;
    }
    return result;
}

int checkTime(char hour[],char minute[])
{
    int result=1;
    int number_hour=0;
    int number_minute=0;

    number_hour=atoi(hour);
    number_minute=atoi(minute);

    if(number_hour>23 || number_hour<0)
    {
        printf("Invalid - illegal hour\n");
        result=0;
    }
    else if(number_minute>59 || number_minute<0)
    {
        printf("Invalid - illegal minutes\n");
        result=0;
    }
    return result;
}

int checkDay(char year[],char month[],char day[])
{
    int number_month=0;
    int number_day=0;
    int number_year=0;
    int result=1;

    number_year=atoi(year);
    number_month=atoi(month);
    number_day=atoi(day);

    if(number_month==1 || number_month==3 || number_month==5 || number_month==7
       || number_month==8 || number_month==10 || number_month==12)
    {
        if(number_day<1 || number_day>31)
        {
            printf("Invalid - wrong number of days of month\n");
            result=0;
        }
    }
    else if(number_month==4 || number_month==6 || number_month==9 || number_month==11 )
    {
        if(number_day<1 || number_day>30)
        {
            printf("Invalid - wrong number of days of month\n");
            result=0;
        }
    }
    else if(number_month == 2)
    {
        if(number_year % 4 != 0)
        {
            if(number_day>28)
            {
                printf("Invalid - wrong number of days of month\n");
                result=0;
            }
        }
        if(number_year % 4 == 0)
        {
            if(number_day>29)
            {
                printf("Invalid - wrong number of days of month\n");
                result=0;
            }
        }
    }
    return result;
}

int checkValidationInternationalPhoneNumber()
{
    char input[64];
    char phone[64];
    char front[32];
    char middle[32];
    char last[32];
    int result=1;
    int count=0;


    printf("\nValidate international phone number\n");
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
        count++;
        printf("\tEnter phone number: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",phone);
        sscanf(phone,"+%[^-]-%[^-]-%[^\n]",front,middle,last);
    }
    return count;
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

int checkValidationHotelServicesCode()
{
    char input[64];
    char hotelCode[64];
    int result=1;
    int count=0;

    printf("\nValidate Hotel services code\n");
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
        count++;
        printf("\tEnter hotel services code: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",hotelCode);
    }
    return count;
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

int checkValidationStreetAddressInBangkok()
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
    int count=0;

    printf("\nValidate street address in Bangkok\n");
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
        count++;
        printf("\tEnter street address in Bangkok: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]",address);
    }
    return count;
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
