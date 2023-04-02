#include <stdio.h>

int isPrime(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int m,n;
    printf("Enter 2 numbers : \t");
    scanf("%d %d",&m,&n);
    int gcd=1,i=2;
    int t=m>n?n:m;
    while(i<t)
    {
        if(isPrime(i))
        {
            if(m%i==0&&n%i==0)
            {
                gcd *= i;
                m /= i;
                n /= i;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("\nGCD is %d\n\n",gcd);
}