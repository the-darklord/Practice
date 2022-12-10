#include "intstack.c"

void main()
{
	STACKINT s1,*ptr=&s1;
	int k,n;
	printf("\nEnter Array Size : \t");
	scanf("%d",&n);
	ptr->size=n;
	ptr->top=-1;
	ptr->stack=(int *)malloc(ptr->size*sizeof(int));
	int arr[n];
	printf("\nEnter Array Elements : \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEntered Array Elements : \t");
	for(int i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
	printf("\nEnter Number of Elements to Delete : \t");
	scanf("%d",&k);
	while(k!=0)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]<arr[i+1])
			{
				k--;
				n--;
				int j=n;
				while(j!=i-1)
				{
					push(ptr,arr[j]);
					j--;
				}
				pop(ptr);
				j=i;
				while(ptr->top!=-1)
				{
					arr[j]=pop(ptr);
					j++;
				}
				break;
			}
		}
	}
	printf("\nNew Array after Deletion : ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}