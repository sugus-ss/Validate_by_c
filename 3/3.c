/*3.c*/
/*This program check validation date and time in form yyyy-mm-dd hh:tt*/
/*Pornsawalee Gus 63070503467 11 June 2021*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkAllDigits_date_time(char date_time[]);
int checkFormat(char date_time[]);
int checkYearMonthDay(char year[],char month[],char day[]);
int checkTime(char hour[],char minute[]);
int checkDay(char year[],char month[],char day[]);

int main()
{
    char input[64];
    char date_time[64];
    int result=1;
    char year[32];
    char month[32];
    char day[32];
    char hour[32];
    char minute[32];

    printf("Validate Western date and time in form yyyy-mm-dd hh:tt\n");
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
        printf("\tEnter your date and time ");
        fgets(date_time,sizeof(date_time),stdin);
        sscanf(date_time,"%[^-]-%[^-]-%[^ ] %[^:]:%[^\n]",year,month,day,hour,minute);
    }
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

