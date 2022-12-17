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


void pretopost(char str[])
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
            strcpy(val,op1);
            strcat(val,op2);
            strcat(val,x);
            push(ptr,val);
        }
        i++;
    }
    char rev[100];
    strcpy(rev,pop(ptr));
    for(int i=0;i<n/2;i++)
    {
        temp=rev[i];
        rev[i]=rev[n-i-1];
        rev[n-i-1]=temp;
    }
    printf("Postfix Expression is %s",rev);
}

void main()
{
	char prefix[100];
	printf("Enter a Prefix Expression : \t");
	scanf("%s",prefix);
	pretopost(prefix);
}