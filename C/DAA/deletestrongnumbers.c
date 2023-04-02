#include <stdio.h>

int factorial(int n)
{
    int fact=1;
    for(int i=n;i>0;i--)
    {
        fact *= i;
    }
    return fact;
}

int isStrongNum(int n)
{
    int t=n;
    int rem;
    int sum=0;
    while(t>0)
    {
        rem=t%10;
        t /= 10;
        sum += factorial(rem);
    }
    if(sum==n)
    {
        return 1;
    }
    return 0;
}

void main()
{
    int n;
    printf("Enter Array Size : \t");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int newarr[n];
    int l=0;
    for(int i=0;i<n;i++)
    {
        if(!isStrongNum(arr[i]))
        {
            newarr[l++]=arr[i];
        }
    }
    printf("\nNew Array is \n");
    for(int i=0;i<l;i++)
    {
        printf("%d ",newarr[i]);
    }
    printf("\n\n");
}