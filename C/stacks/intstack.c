#include <stdio.h>
#include <stdlib.h>

typedef struct STACKINT
{
    int size,top,*stack;
}STACKINT;

void push(STACKINT *ptr,int ele)
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

int pop(STACKINT *ptr)
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

void Display(STACKINT *ptr)
{
    for(int i=0;i<=ptr->top;i++)
    {
        printf("%d \t",ptr->stack[i]);
    }
    printf("\n");
}