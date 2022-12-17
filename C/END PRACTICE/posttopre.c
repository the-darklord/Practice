#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct STACKSTRING
{
    char **stack;
    int size;
    int top;
}STACKSTRING;

void push(STACKSTRING *ptr,char x[])
{
    if(ptr->top==ptr->size-1)
    {
        printf("Stack OverFlow !!");
    }
    else
    {
        strcpy(ptr->stack[++ptr->top],x);
    }
}

char* pop(STACKSTRING *ptr)
{
    if(ptr->top==-1)
    {
        printf("Stack UnderFlow !!");
        return " '\0'";
    }
    else
    {
        return ptr->stack[ptr->top--];
    }
}


void posttopre(char str[])
{
    STACKSTRING s1,*ptr=&s1;
    ptr->top=-1;
    int n=strlen(str);
    ptr->size=n;
    ptr->stack=(char **)calloc(ptr->size,sizeof(char *));
    for(int i=0;i<n;i++)
    {
        ptr->stack[i]=(char *)malloc(100*sizeof(char));
    }
    int i=0;
    while(str[i]!='\0')
    {
        if(isalnum(str[i]))
        {
            char x[2];
            x[0]=str[i];
            x[1]='\0';
            push(ptr,x);
        }
        else
        {
            char op2[100];
            strcpy(op2,pop(ptr));
            char op1[100];
            strcpy(op1,pop(ptr));
            char x[2];
            x[0]=str[i];
            x[1]='\0';
            char val[100];
            strcpy(val,x);
            strcat(val,op1);
            strcat(val,op2);
            push(ptr,val);
        }
        i++;
    }
    printf("Prefix Expression is %s",pop(ptr));
}

void main()
{
	char postfix[100];
	printf("Enter a Postfix Expression : \t");
	scanf("%s",postfix);
	posttopre(postfix);
}