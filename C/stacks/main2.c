#include "charstack.c"

void main()
{
    int n;
    STACKCHAR s1,*ptr=&s1;
    printf("\nEnter Stack Size : \t");
    scanf("%d",&n);
    ptr->size=n;
    ptr->top=-1;
    ptr->stack=(char *)malloc(ptr->size*sizeof(char));
    push(ptr,'M');
    push(ptr,'N');
    Display(ptr);
}