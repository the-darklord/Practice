#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,fact=1;

    printf("Enter a Number : ");
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        fact=fact*i;
    }

    printf("The Factorial of given Number is : %d",fact);
    return 0;
}