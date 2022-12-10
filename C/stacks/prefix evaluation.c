#include "charstack.c"
#include <string.h>
#include <ctype.h>

int evaluate(char x,int op1,int op2)
{
    switch(x)
    {
        case '+':
        {
            return (op1+op2);
        }
        case '-':
        {
            return (op1-op2);
        }
        case '*':
        {
            return (op1*op2);
        }
        case '/':
        {
            return (op1/op2);
        }
        case '%':
        {
            return (op1%op2);
        }
    }
}

void main()
{
	STACKCHAR s1,*ptr=&s1;
	ptr->top=-1;
	char str[100];
	printf("\nEnter a prefix expression : \n");
	scanf("%s",str);
	int n=strlen(str),op1,op2,val;
	ptr->size=n;
	ptr->stack=(char *)malloc(ptr->size*sizeof(char));
	char temp;
	for(int i=0;i<n/2;i++)
	{
		temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
	int i=0;
	while(str[i]!='\0')
	{
		if(isdigit(str[i]))
		{
			push(ptr,str[i]-'0');
		}
		else
		{
			op1=pop(ptr);
			op2=pop(ptr);
			val=evaluate(str[i],op1,op2);
			push(ptr,val);
		}
		i++;
	}
	val=pop(ptr);
	printf("\nValue of Prefix Expression is : %d",val);
}