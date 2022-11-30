#include <stdio.h>

int main()
{
	int num,prime,i,pc=0,cc=0;
	
	do
	{
		printf("Enter a number : \n");
		scanf("%d",&num);
		
		if(num>1)
		{
			prime=0;
			i=2;
			while(i<=num/2)
			{
				if(num%i==0)
				{
					prime=1;
					break;
				}
				i++;
			}
			if(prime==0)
				pc++;
			else
				cc++;
			num++;
		}
		
	}
	while(num!=-1);
	
	printf("No of prime numbers are %d \n",pc);
	printf("No of composite numbers are %d \n",cc);
	
	return 0;
}