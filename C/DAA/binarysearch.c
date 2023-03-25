/*
ALGORITHM BinarySearch(A[0..n-1],k)
    l ← 0
    r ← n-1
    while l≤r
        m ← |_(l+r)/2_|
        if k=A[m]
            return m
        else if k<A[m]
            r ← m-1
        else
            l ← m+1
    return -1
*/

#include <stdio.h>

void InsertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int v=A[i];
        int j=i-1;
        while(j>=0&&A[j]>v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
}

int BinarySearch(int A[],int n,int k)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(k==A[m])
        {
            return 1;
        }
        else if(k>A[m])
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return 0;
}

void main()
{
    int n,k;
    printf("Enter Array Length : \t");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter Element to Find : \t");
    scanf("%d",&k);
    InsertionSort(A,n);
    int t=BinarySearch(A,n,k);
    if(t)
    {
        printf("\nElement Not Found\n\n");
    }
    else
    {
        printf("\nElement Found\n\n");
    }
}