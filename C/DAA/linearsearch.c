/*
ALGORITHM LinearSearch(A[0..n-1],k)
    i ← 0
    while i<n and A[i]≠k do
        i ← i+1
    if i<n
        return i
    return -1
*/

#include <stdio.h>

void main()
{
    int n;
    printf("Enter Array Length : \t");
    scanf("%d",&n);
    int A[n];
    printf("Enter Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int k;
    printf("Enter Element to Search : \t");
    scanf("%d",&k);
    int i=0;
    while(i<n&&A[i]!=k)
    {
        i++;
    }
    if(i<n)
    {
        printf("Element Found at Position %d\n",i+1);
    }
    else
    {
        printf("Element Not Found\n");
    }
}