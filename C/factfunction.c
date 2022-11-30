#include <stdio.h>
#include <conio.h>

long int factFn(int num)
{
    int i;
    long int fact=1;

    for (i=1;i<=num;i++)
    {
        fact=fact*i;
    }

    return (fact);
}

int main()
{
    int n;
    long int f;
    printf("Enter a number : ");
    scanf("%d",&n);

    f=factFn(n);
    printf("Factorial of given number = %ld",f);
    return 0;
}