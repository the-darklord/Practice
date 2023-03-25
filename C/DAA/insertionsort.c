/*
ALGORITHM InsertionSort(A[0..n-1])
    for i ← 1 to n-1
        v ← A[i]
        j ← i-1
        while j ≥ 0 and A[j]>v
            A[j+1] ← A[j]
            j ← j-1
        A[j+1] ← v
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

void main()
{
    int n;
    printf("Enter Array Length : \t");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    InsertionSort(A,n);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n\n");
}