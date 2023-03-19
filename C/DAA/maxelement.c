/*
ALGORITHM MaxElement(A[0..n-1])
    maxval ← A[0]
    for i ← 1 to n-1 do
        if A[i]>maxval
            maxval ← A[i]
    return maxval
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
    int max=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    printf("MaxElement is %d\n",max);
}