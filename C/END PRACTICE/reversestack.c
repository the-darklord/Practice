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
    for(int t=ptr->top;t!=-1;t--)
    {
        printf("%d \t",ptr->stack[t]);
    }
}

void main()
{
    STACKINT s1,*ptr=&s1;
    ptr->top=-1;
    int n,x;
    printf("Enter Stack Size : \t");
    scanf("%d",&n);
    ptr->size=n;
    ptr->stack=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d : \t",i+1);
        scanf("%d",&x);
        push(ptr,x);
    }
    printf("\nInitial Stack : \n");
    display(ptr);
    int arr[n];
    int i=0;
    while(ptr->top!=-1)
    {
        arr[i++]=pop(ptr);
    }
    for(i=0;i<n;i++)
    {
        push(ptr,arr[i]);
    }
    printf("\nReversed Stack : \n");
    display(ptr);
}