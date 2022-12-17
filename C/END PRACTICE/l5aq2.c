#include <stdio.h>
#include <stdlib.h>

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

void NGE(STACKINT *ptr)
{
    if(ptr->top!=-1)
    {
        int x = pop(ptr);
        int nge=-1;
        int n=ptr->top+1;
        int arr[n];
        int i=0;
        int t=n-1;
        while(t!=-1)
        {
            arr[i++]=ptr->stack[t--];
        }
        for(i=0;i<n;i++)
        {
            if(x<arr[i])
            {
                nge=arr[i];
                break;
            }
        }
        printf("\n%d => %d\n",x,nge);
        NGE(ptr);
    }
}

void main()
{
	STACKINT s1,*ptr=&s1;
	int arr[] = {13,7,6,12,15};
	int n = sizeof(arr)/sizeof(arr[0]);
	ptr->top=-1;
	ptr->size=n;
	ptr->stack=(int *)malloc(sizeof(int));
	for(int i=0;i<n;i++)
	{
	    push(ptr,arr[n-i-1]);
	}
	NGE(ptr);
}