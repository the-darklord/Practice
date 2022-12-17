#include <string.h>

typedef struct STACKSTRING
{
    char *stack[100];
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

void display(STACKSTRING *ptr)
{
    for(int t=ptr->top;t!=-1;t--)
    {
        printf("%s \t",ptr->stack[t]);
    }
}