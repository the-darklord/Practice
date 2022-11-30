#include <stdio.h>
#include <conio.h>

int Swap(int n,int m)
{
    n=n+m;
    m=n-m;

    n=n-m;

    printf("\n Numbers After Swap are %d , %d",n,m);
    return 0;
}

int main()
{
    int a,b;

    printf("Enter First Number : \t");
    scanf("%d",&a);

    printf("Enter Second Number : \t");
    scanf("%d",&b);

    printf("\n Numbers Before Swap are %d , %d",a,b);

    Swap(a,b);

    return 0;
}