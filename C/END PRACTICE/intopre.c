#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct STACKCHAR
{
    char *stack;
    int size;
    int top;
}STACKCHAR;

void push(STACKCHAR *ptr,char x)
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

char pop(STACKCHAR *ptr)
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

void display(STACKCHAR *ptr)
{
    for(int t=ptr->top;t!=-1;t--)
    {
        printf("%c \t",ptr->stack[t]);
    }
}

char peek(STACKCHAR *ptr)
{
    return ptr->stack[ptr->top];
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                    return 1;
        case '*':
        case '/':
        case '%':
                    return 2;
        case '^':
                    return 3;
        default:
                    return 0;
    }
    return -1;
}

void intopre(char str[])
{
    STACKCHAR s1,*ptr=&s1;
    ptr->top=-1;
    int n=strlen(str);
    char temp;
    for(int i=0;i<n/2;i++)
    {
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    char pre[n];
    ptr->size=n;
    ptr->stack=(char *)malloc(ptr->size*sizeof(char));
    int i=0,j=0;
    while(str[i]!='\0')
    {
        if(isalnum(str[i]))
        {
            pre[j++]=str[i];
        }
        else if(str[i]==')')
        {
            push(ptr,str[i]);
        }
        else if(str[i]=='(')
        {
            char x;
            while((x=pop(ptr))!=')')
            {
                pre[j++]=x;
            }
        }
        else
        {
            while(precedence(peek(ptr))>precedence(str[i]))
            {
                pre[j++]=pop(ptr);
            }
            push(ptr,str[i]);
        }
        i++;
    }
    while(ptr->top!=-1)
    {
        pre[j++]=pop(ptr);
    }
    pre[j++]='\0';
    int m=strlen(pre);
    for(int k=0;k<m/2;k++)
    {
        temp=pre[k];
        pre[k]=pre[m-k-1];
        pre[m-k-1]=temp;
    }
    printf("\nPrefix Expression : \t%s",pre);
}

void main()
{
    char str[100];
    printf("Enter fully paranthesized infix expression : \n");
    scanf("%s",str);
    intopre(str);
}