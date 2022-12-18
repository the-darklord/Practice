#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct STACKINT
{
    int *stack;
    int size;
    int top;
}STACKINT;

void push(STACKINT *ptr,int x)
{
    if(ptr->top==ptr->size-1)
    {
        printf("Stack OverFlow !!");
    }
    else
    {
        ptr->stack[++ptr->top]=x;
    }
}

int pop(STACKINT *ptr)
{
    if(ptr->top==-1)
    {
        printf("Stack UnderFlow !!");
        return -1;
    }
    else
    {
        return ptr->stack[ptr->top--];
    }
}

void display(STACKINT *ptr)
{
    for(int t=ptr->top;t!=-1;t++)
    {
        printf("%d \t",ptr->stack[t]);
    }
}

int eval(int op1,int op2,char c)
{
    switch(c)
    {
        case '+' :
        {
            return op1+op2;
        }
        case '-' :
        {
            return op1-op2;
        }
        case '*' :
        {
            return op1*op2;
        }
        case '/' :
        {
            return op1/op2;
        }
        case '%' :
        {
            return op1%op2;
        }
    }
}

void prefixeval(char str[])
{
    STACKINT s1,*ptr=&s1;
    ptr->top=-1;
    int n=strlen(str);
    ptr->size=n;
    ptr->stack=(int *)malloc(ptr->size*sizeof(int));
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
        if(isalnum(str[i]))
        {
            push(ptr,str[i]-'0');
        }
        else
        {
            int op1=pop(ptr);
            int op2=pop(ptr);
            int val=eval(op1,op2,str[i]);
            push(ptr,val);
        }
        i++;
    }
    printf("Value of Prefix Expression is %d",pop(ptr));
}

void main()
{
	STACKINT s1,*ptr=&s1;
	char prefix[100];
	printf("Enter a Prefix Expression : \t");
	scanf("%s",prefix);
	prefixeval(prefix);
}