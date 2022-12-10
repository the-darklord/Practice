#include "intstack.c"

void main()
{
	STACKINT s1,*ptr=&s1;
	ptr->top=-1;
	ptr->size=2;
	ptr->stack=(int *)malloc(ptr->size*sizeof(int));
	int n,rem;
	printf("\nEnter a Number : \t");
	scanf("%d",&n);
	while(n>0)
	{
		rem=n%2;
		if(ptr->top==(ptr->size)-1)
		{
			(ptr->size)*=2;
			ptr->stack=(int *)realloc(ptr->stack,ptr->size*sizeof(int));
		}
		push(ptr,rem);
		n/=2;
	}
	printf("\nBinary Number is : ");
	while(ptr->top!=-1)
	{
		printf("%d",pop(ptr));
	}
}