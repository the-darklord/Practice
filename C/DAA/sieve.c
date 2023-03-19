/*
ALGORITHM Sieve(n)
    for p ← 2 to n do
        A[p] ← p
    for p ← 2 to |_√n_| do
        if A[p] ≠ 0
            j ← p*p
            while j≤n
                A[j] ← 0
                j ← j+p
    i ← 0
    for p ← 2 to n do
        if A[p] ≠ 0
            L[i] ← A[p]
            i ← i+1
    return L
*/

#include <stdio.h>
#include <math.h>

void main()
{
    int n;
    printf("Enter a Number : \t");
    scanf("%d",&n);
    int A[n],L[n];
    for(int i=2;i<=n;i++)
    {
        A[i]=i;
    }
    int j;
    for(int i=2;i<sqrt(n);i++)
    {
        if(A[i]!=0)
        {
            j=i*i;
            while(j<=n)
            {
                A[j]=0;
                j+=i;
            }
        }
    }
    j=0;
    for(int i=2;i<=n;i++)
    {
        if(A[i]!=0)
        {
            L[j++]=A[i];
        }
    }
    printf("\nPrime Numbers before %d are\n",n);
    for(int i=0;i<j;i++)
    {
        printf("%d ",L[i]);
    }
}