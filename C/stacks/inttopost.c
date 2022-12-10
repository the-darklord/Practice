#include "charstack.c"
#include <string.h>
#include <ctype.h>

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void main()
{
	STACKCHAR s1,*ptr=&s1,s2,*pt=&s2;
	ptr->top=-1;
	pt->top=-1;
	char str[100];
	printf("\nEnter an infix expression : \n");
	scanf("%s",str);
	char temp,x;
	int i,n=strlen(str);
	ptr->size=pt->size=n;
	ptr->stack=(char *)malloc(ptr->size*sizeof(char));
	pt->stack=(char *)malloc(pt->size*sizeof(char));
    i=0;
	while(str[i]!='\0')
	{
		if(isdigit(str[i]))
		{
			push(pt,str[i]);
		}
		else if(str[i]=='(')
		{
			push(ptr,str[i]);
		}
		else if(str[i]==')')
		{
			while((x=pop(ptr))!='(')
			{
				push(pt,x);
			}
		}
		else
		{
			while(priority(ptr->stack[ptr->top])>=priority(str[i]))
			{
				push(pt,pop(ptr));
			}
			push(ptr,str[i]);
		}
		i++;
	}
	while(ptr->top!=-1)
	{
		push(pt,pop(ptr));
	}
	while(pt->top!=-1)
	{
		push(ptr,pop(pt));
	}
	while(ptr->top!=-1)
	{
		printf("%c",pop(ptr));
	}
	printf("\n");
}