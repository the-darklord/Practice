#include <stdio.h>
#include <stdlib.h>

typedef struct STACKCHAR
{
    int size,top;
    char *stack;
}STACKCHAR;

void push(STACKCHAR *ptr,char ele)
{
    if(ptr->top==(ptr->size)-1)
    {
        printf("\nStack Full \n");
        exit(1);
    }
    else
    {
        ptr->stack[++(ptr->top)]=ele;
    }
}

char pop(STACKCHAR *ptr)
{
    if(ptr->top==-1)
    {
        printf("\nStack Empty\n");
        exit(1);
    }
    else
    {
        return ptr->stack[(ptr->top)--];
    }
}

void Display(STACKCHAR *ptr)
{
    for(int i=0;i<=ptr->top;i++)
    {
        printf("%c \t",ptr->stack[i]);
    }
    printf("\n");
}