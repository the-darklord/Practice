/*
ALGORITHM Factorial(n)
    if n=0
        return 1
    else
        return n*Factorial(n-1)
*/

#include <stdio.h>

int Factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*Factorial(n-1);
}

void main()
{
    int n;
    printf("\nEnter a Number : \t");
    scanf("%d",&n);
    printf("\nFactorial of %d id %d\n\n",n,Factorial(n));
}