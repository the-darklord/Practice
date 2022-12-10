#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACKSTRING
{
    int size,top;
    char *stack[100];
}STACKSTRING;

void push(STACKSTRING *ptr,char ele[])
{
    if(ptr->top==(ptr->size)-1)
    {
        printf("\nStack Full \n");
        exit(1);
    }
    else
    {
        strcpy(ptr->stack[++(ptr->top)],ele);
    }
}

char* pop(STACKSTRING *ptr)
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

void Display(STACKSTRING *ptr)
{
    for(int i=0;i<=ptr->top;i++)
    {
        printf("%s \t",ptr->stack[i]);
    }
    printf("\n");
}