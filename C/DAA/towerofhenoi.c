/*
ALGORITHM TowerOfHenoi(n,S,A,D)
    if n=1
        Display(Moving from S to D)
    else
        TowerOfHenoi(n-1,S,D,A)
        Display(Moving from S to D)
        TowerOfHenoi(n-1,A,S,D)
*/

#include <stdio.h>

void TowerOfHenoi(int n,char S,char A,char D)
{
    if(n==1)
    {
        printf("Moving from %c to %c\n",S,D);
    }
    else
    {
        TowerOfHenoi(n-1,S,D,A);
        printf("Moving from %c to %c\n",S,D);
        TowerOfHenoi(n-1,A,S,D);
    }
}

void main()
{
    int n;
    printf("Enter No. of Disks : \t");
    scanf("%d",&n);
    TowerOfHenoi(n,'A','B','C');
    printf("\n");
}