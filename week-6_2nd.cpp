#include<stdio.h>
#include<string.h>
int s(),l(),LDASH();
char *IP;
char string[50];
int main()
{
	printf("ENTER THE STRING : ");
	scanf("%s",string);
	IP = string;
	printf("\n\nInput\tAction\n--------------------------------\n");
	if(s() && *IP=='\0'){
		printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
	}
	else{
		printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
	}
}

int s()
{
	if(*IP=='(')
	{
		printf("%s\tS->(L)\n",IP);
		IP++;
		if(l())
		{
			if(*IP==')')
			{
				printf("%s\tS->(L)\n",IP);
				IP++;
				return 1;
			}
			else
			    return 0;
		}
		else 
		return 0;
	}
	else if(*IP=='a')
	{
		printf("%s\tS->a\n",IP);
		IP++;
		return 1;
	}
	else
	    return 0; 
}

int l()
{
	printf("%s\tL->SL'\n",IP);
	if(s())
	{
		if(LDASH())
		{
			return 1;
		}
		else 
		    return 0;
		
	}
	else 
	return 0;
}

int LDASH()
{
	if(*IP==',')
	{
		printf("%s\tL'->,SL'\n",IP);
		IP++;
		if(s())
		{
			if(LDASH())
			{
				return 1;
			}
			else
			    return 0;
		}
	    else
		return 0;	
    }
    else
    printf("%s\tL'->^\n",IP);
    return 1;

}

