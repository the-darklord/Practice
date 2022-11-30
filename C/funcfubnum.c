#include <stdio.h>
#include <conio.h>

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return (fib(n-1)+fib(n-2));
    }
}

int main()
{
    int n,i,a[20],fibo;

    printf("Enter a Number : \t");
    scanf("%d",&n);

    printf("Fibonacci series is \n");

    for(i=0;i<n;i++)
    {
        fibo=fib(i);
        printf("%d \t",fibo);
    }

    return 0;
}