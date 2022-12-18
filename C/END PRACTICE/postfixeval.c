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

void postfixeval(char str[])
{
    STACKINT s1,*ptr=&s1;
    ptr->top=-1;
    int n=strlen(str);
    ptr->size=n;
    ptr->stack=(int *)malloc(ptr->size*sizeof(int));
    char temp;
    int i=0;
    while(str[i]!='\0')
    {
        if(isalnum(str[i]))
        {
            push(ptr,str[i]-'0');
        }
        else
        {
            int op2=pop(ptr);
            int op1=pop(ptr);
            int val=eval(op1,op2,str[i]);
            push(ptr,val);
        }
        i++;
    }
    printf("Value of Postfix Expression is %d",pop(ptr));
}

void main()
{
	STACKINT s1,*ptr=&s1;
	char postfix[100];
	printf("Enter a Postfix Expression : \t");
	scanf("%s",postfix);
	postfixeval(postfix);
}