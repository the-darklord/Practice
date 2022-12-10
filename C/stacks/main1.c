#include "intstack.c"

void main()
{
    int n;
    STACKINT s1,*ptr=&s1;
    printf("\nEnter Stack Size : \t");
    scanf("%d",&n);
    ptr->size=n;
    ptr->top=-1;
    ptr->stack=(int *)malloc(ptr->size*sizeof(int));
    push(ptr,1);
    push(ptr,3);
    Display(ptr);
}