/*
ALGOTITHM EUCLID(m,n)
    while n≠0 do 
        r ← m mod n
        m ← n
        n ← r 
    return m
*/

#include <stdio.h>

void main()
{
    int m,n;
    printf("Enter 2 Numbers : \t");
    scanf("%d %d",&m,&n);
    int m1=m,n1=n;
    int r;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    printf("\nGCD of %d and %d is %d\n",m1,n1,m);
}