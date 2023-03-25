/*
ALGORITHM MatrixMultiplication(A[0..n-1,0..n-1],B[0..n-1,0..n-1])
    for i ← 0 to n-1 do
        for j ← 0 to n-1 do
            c[i,j] ← 0
            for k ← 0 to n-1 do
                C[i,j] ← C[i,j] + A[i,k]*B[k,j]
    return C
*/

#include <stdio.h>

void readmat(int M[][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
}

void displaymat(int M[][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf(" %d ",M[i][j]);
        }
        printf("\n");
    }
}

void matrixmult(int A[][100],int B[][100],int r1,int r2,int c2,int C[][100])
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            C[i][j]=0;
            for(int k=0;k<r2;k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void main()
{
    int r1,r2,c1,c2;
    printf("Enter Dimensions of Matrix A : \t");
    scanf("%d %d",&r1,&c1);
    printf("Enter Dimensions of Matrix B : \t");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2)
    {
        printf("\nMatrices can't be Multiplied\n\n");
    }
    else
    {
        int A[r1][c1],B[r2][c2],C[r1][c2];
        printf("\nEnter Matrix A : \n");
        readmat(A,r1,c1);
        printf("\nEnter Matrix B : \n");
        readmat(B,r2,c2);
        printf("\nMatrix A : \n");
        displaymat(A,r1,c1);
        printf("\nMatrix B : \n");
        displaymat(B,r2,c2);
        printf("\nResultant Matrix is : \n");
        matrixmult(A,B,r1,r2,c2,C);
        displaymat(C,r1,c2);
    }
}