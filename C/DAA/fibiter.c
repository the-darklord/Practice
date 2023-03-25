/*
ALGORITHM Fib(n)
    l ← 0
    u ← 1
    for i ← 2 to n do
        t ← u
        u ← u+l
        l ← t
    return u
*/

#include <stdio.h>

int Fib(int n)
{
    int l=0,u=1,t;
    for(int i=2;i<=n;i++)
    {
        t=u;
        u+=l;
        l=t;
    }
    return u;
}

void main()
{
    int n;
    printf("Enter a Number : \t");
    scanf("%d",&n);
    printf("\nFibonacci Number is %d\n\n",Fib(n-1));
}