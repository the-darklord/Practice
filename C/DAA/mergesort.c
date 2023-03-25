/*
ALGORITHM MergeSort(A[0..n-1])
    if n>1
        copy A[0..n/2 - 1] to B[0..n/2 - 1]
        copy A[n/2 .. n-1] to B[0..n/2]
        MergeSort(B)
        MergeSort(C)
        Merge(B,C,A)

Merge(B[0..p-1],C[0..q-1],A[0..p+q-1])
    i ← 0
    j ← 0
    k ← 0
    while i<p and j<q
        if B[i]≤C[j]
            A[k] ← B[i]
            i ← i+1
        else
            A[k] ← C[j]
            j ← j+1
        k ← k+1
    if i=p
        copy C[j..q-1] to A[k..p+q-1]
    else
        copy B[i..p-1] to A[k..p+q-1]
*/

#include <stdio.h>

void Merge(int B[],int b,int C[],int c,int A[])
{
    int i=0,j=0,k=0;
    while(i<b&&j<c)
    {
        if(B[i]<=C[j])
        {
            A[k++]=B[i++];
        }
        else
        {
            A[k++]=C[j++];
        }
    }
    while(i<b)
    {
        A[k++]=B[i++];
    }
    while(j<c)
    {
        A[k++]=C[j++];
    }
}

void MergeSort(int A[],int n)
{
    if(n>1)
    {
        int t=n/2;
        int B[t],C[n-t];
        for(int i=0;i<t;i++)
        {
            B[i]=A[i];
        }
        for(int i=t;i<n;i++)
        {
            C[i-t]=A[i];
        }
        MergeSort(B,t);
        MergeSort(C,n-t);
        Merge(B,t,C,n-t,A);
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
    MergeSort(A,n);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n\n");
}