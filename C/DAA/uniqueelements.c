/*
ALGORITHM UniqueElements(A[0..n-1])
    for i ← 0 to n-2 do
        for j ← i+1 to n-1 do
            if A[i]=A[j]
                return false
    return true
*/

#include <stdio.h>
#define true 1
#define false 0

int unique(int A[100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
            {
                return false;
            }
        }
    }
    return true;
}

void main()
{
    int n;
    printf("Enter No. of elements  :\t");
    scanf("%d",&n);
    int arr[n];
    printf("\n Enter Array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int flag=unique(arr,n);
    if(flag)
    {
        printf("\nElements are Unique\n\n");
    }
    else
    {
        printf("\nElements are not Unique\n\n");
    }
}
