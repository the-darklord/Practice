/*
ALGORITHM QuickSort(A[l..r])
    if l<r
        s ← Partition(A[l..r])
        QuickSort(A[l..s-1])
        QuickSort(A[s+1..r])

Partition(A[l..r])
    p ← A[l]
    i ← l
    j ← r+1
    repeat
        repeat i ← i+1 until A[i]≥p
        repeat j ← j-1 until A[j]≤p
        swap(A[i],A[j])
    until i≥j
    swap(A[i],A[j])
    swap(A[l],A[j])
    return j
*/

#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int A[],int l,int r)
{
    int p=A[l];
    int i=l,j=r+1;
    do
    {
        do
        {
            i++;
        }while(A[i]<p&&i<=r);
        do
        {
            j--;
        }while(A[j]>p);
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int r)
{
    if(l<r)
    {
        int s=Partition(A,l,r);
        QuickSort(A,l,s-1);
        QuickSort(A,s+1,r);
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
    QuickSort(A,0,n-1);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n\n");
}