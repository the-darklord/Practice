/*
ALGORITHM BinCount(n)
    count ← 1
    while n>1 do
        count ← count + 1
        n=|_n/2_|
    return count
*/

#include <stdio.h>

int BinCount(int n)
{
    int count=1;
    while(n>1)
    {
        count+=1;
        n/=2;
    }
    return count;
}

void main()
{
    int n;
    printf("\nEnter a Number : \t");
    scanf("%d",&n);
    printf("\nNo. of Digits in Binary Representation of %d is %d\n\n",n,BinCount(n));
}