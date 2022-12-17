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