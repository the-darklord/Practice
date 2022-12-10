#include "charstack.c"
#include <string.h>

void main()
{
	STACKCHAR s1,*ptr=&s1;
	char x,str[100];
	printf("Enter a String : \n");
	scanf("%[^\n]s",str);
	int n=strlen(str);
	ptr->size=n;
	ptr->top=-1;
	ptr->stack=(char *)malloc(ptr->size*sizeof(char));
	int i=0,flag;
	while(str[i]!='\0')
	{
		push(ptr,str[i]);
		i++;
	}
	for(int j=0;j<n/2;j++)
	{
		flag=1;
		x=pop(ptr);
		if(str[j]!=x)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("\nPalindrome\n");
	}
	else
	{
		printf("\nNot a Palindrome\n");
	}
}