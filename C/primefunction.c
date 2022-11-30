#include <stdio.h>
#include <conio.h>

int Prime(int num)
{
    int p=1;
    for (int j=2;j<num/2;j++)
    {
        if(num%j==0)
        {
        p=0;
        break;
        }
    }
    return (p);
}

int main ()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if (Prime(n))
    {
    printf("%d is a Prime Number",n);
    }
    else
    {
    printf("%d is not a Prime Number",n);
    }

    return 0;
}