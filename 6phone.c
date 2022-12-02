/*This program check validation Thai phone number*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int ckeckDigits(char phone[]); 
int checkCountDigits(char phone[]);
int checkPrefixPhone(char phone[]);
int checkCountDashes(char phone[]);
int checkIndexDashes(char phone[]);
int checkFinalIndex(char phone[]);

int main()
{
	char input[64];
	char phone[64];
	int result=1;
	
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^\n]",phone);
	while(strlen(phone) != 0)
	{	
		if(result != 0)
		{		
			result = ckeckDigits(phone);
			if(result != 0)
			{	
				result =  checkCountDigits(phone);
				if(result != 0)
				{
					result = checkPrefixPhone(phone);
					if(result != 0)
					{
						result = checkCountDashes(phone); 
						if(result != 0)
						{
							result = checkIndexDashes(phone);
							if(result != 0)
							{
								result = checkFinalIndex(phone);
								if(result != 0)
								{
								printf("Valid\n");
								}
							}							
						}				
					}
				}
			}		
		}
		result=1;
		memset(phone,0,sizeof(phone));
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%[^\n]",phone);
	}
}

/*This fuction check input is digit or not*/
int ckeckDigits(char phone[])
{
	int result=1;
	int i=0;
	
	for(i=0 ; i<strlen(phone) ; i++)
	{
		if(!isdigit(phone[i]))
		{
			if(phone[i] != '-')
			{
				printf("Invalid - must be digits\n");
				result=0;
				break;				
			}			
		}		
	}
	return result;
}

/*check count of number of digits*/
int checkCountDigits(char phone[])
{
	int result=1;
	int i=0;
	int count=0;
	
	for(i=0 ; i<strlen(phone) ; i++)
	{
		if(isdigit(phone[i]))
		{
			count++;		
		}		
	}
	if(count != 10)
	{
		printf("Invalid - wrong length of numbers\n");
		result=0;
	}
	return result;
}

int checkPrefixPhone(char phone[])
{
	int result=1;
	
	if(phone[0] != '0')
	{
		printf("Invalid - wrong prefix\n");
		result=0;
	}
	else if(phone[0] == '0')
	{
		if(phone[1] == '1' || phone[1] == '5' || phone[1] == '6' || phone[1] == '8'|| phone[1] == '9')
		{
			result=1;
		}
		else
		{
			printf("Invalid - wrong prefix\n");
			result=0;
		}
	}
	return result;

}

int checkCountDashes(char phone[])
{
	int result=1;
	int i=0;
	int dash=0;
	
	for(i=0 ; i<strlen(phone) ; i++)
	{
		if(phone[i] == '-')
		{
			dash++;
		}
	}
	if(dash > 2)
	{
		printf("Invalid - 2 dash allowed\n");
		result=0;
	}
	return result;
}

int checkIndexDashes(char phone[])
{
	int result=1;
	int i=0;
	int dash=0;
	    	  
	if(phone[0] == '-' || phone[1] == '-')
	{
		printf("Invalid - dash in wrong place\n");
		result=0;
	}
	else
	{
		for(i=0 ; i<strlen(phone)-1 ; i++)
		{
			if(phone[i] == '-') 
			{
				if(phone[i+1] == '-')
				{
				printf("Invalid - 2 dashed together\n");
				result=0;
				break;
				}	
				else
				{
				result=1;	
				}
			}
		}	
	}
	return result;
}

int checkFinalIndex(char phone[])
{
	int indexFinal=0;
	int result=1;
	
	indexFinal = strlen(phone)-1;
	if(phone[indexFinal] == '-')
	{
		printf("Invalid - final dash\n");
		result=0;
	}
	return result;
}


