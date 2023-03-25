/*
ALGORITHM SelectionSort(A[0..n-1])
    for i ← 0 to n-2
        min ← i
        for j ← i+1 to n-1
            if A[j] < A[min]
                min ← j
        swap A[i] and A[min]
*/

#include <stdio.h>

void swap(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void SelectionSort(int A[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        swap(&A[i],&A[min]);
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
    SelectionSort(A,n);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n\n");
}