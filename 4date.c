#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"dateFunctions.c"

int main()
{
	char input[256];
	char date[256];
	int result=0;
	int outcome=0;		
	int day=0;
	int month=0;
	int year=0;	
	int day_today=0;
	int month_today=0;
	int year_today=0;	
	char getDay[64];
	char getMonth[64];
	char getYear[64];	
	char number[32];
	char nameMonth[12][32]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	char numberMonth[12][32]={"01","02","03","04","05","06","07","08","09","10","11","12"};
	int i=0;
		
	printf("Enter date (dd mm yyy): ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^ ] %[^ ] %[^\n]",getDay,getMonth,getYear);
	for(i=0 ; i<12 ; i++)
	{
		if(strcmp(getMonth,nameMonth[i]) == 0)
		{
			strcpy(number,numberMonth[i]);
		}		
	}
	sprintf(date,"%s/%s/%s",getDay,number,getYear);
	outcome=checkDate(date, &day, &month, &year);  /*return 0 valid*/
	if(outcome != 0)
	{
		printf("%s is invalid date\n",date);
		result=0;
	}
	else 
	{
		dateToday(&day_today, &month_today, &year_today);
		outcome = dateCompare(day,month,year,day_today,month_today,year_today);
		if(outcome == -1)	/*past*/
		{
			result=1;
		}
		else if(outcome == 1)/*future*/
		{
			result=0;
		}
		else if(outcome == 0)/*present*/
		{				
			result=0;
		}
	}
}


