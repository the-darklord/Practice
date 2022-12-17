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