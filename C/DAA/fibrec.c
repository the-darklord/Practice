/*
ALGORITHM Fib(n)
    if n ≤ 1
        return n
    else
        return Fib(n-1)+Fib(n-2)
*/

#include <stdio.h>

int Fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return Fib(n-1)+Fib(n-2);
}

void main()
{
    int n;
    printf("Enter a Number : \t");
    scanf("%d",&n);
    printf("\nFibonacci Number is %d\n\n",Fib(n-1));
}