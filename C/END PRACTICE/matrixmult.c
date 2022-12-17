#include <stdio.h>
#include <stdlib.h>

void readmatrix(int **t,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter Element %d,%d : \t",i+1,j+1);
            scanf("%d",(*(t+i)+j));
        }
    }
}

void Display(int **t,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d \t",*(*(t+i)+j));
        }
        printf("\n");
    }
}

void matrixmult(int **a,int **b,int **c,int r1,int c2)
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            *(*(c+i)+j)=0;
            for(int k=0;k<c2;k++)
            {
                *(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
            }
        }
    }
}

int main() {
    
    int** a,**b,**c;
    int r1,c1,r2,c2;
    
    printf("Enter No of Rows and Columns of Matrix A : \n");
    scanf("%d %d",&r1,&c1);

    printf("Enter No of Rows and Columns of Matrix B : \n");
    scanf("%d %d",&r2,&c2);
    
    a=(int **)calloc(r1,sizeof(int *));
    b=(int **)calloc(r2,sizeof(int *));
    c=(int **)calloc(r1,sizeof(int *));

    
    for(int i=0;i<r1;i++)
    {
        a[i]=(int *)calloc(c1,sizeof(int));
    }
    
    for(int i=0;i<r2;i++)
    {
        b[i]=(int *)calloc(c2,sizeof(int));
    }
    
    for(int i=0;i<r1;i++)
    {
        c[i]=(int *)calloc(c2,sizeof(int));
    }

    printf("\nEnter Matrix A \n");
    readmatrix(a,r1,c1);

    printf("\nEnter Matrix B \n");
    readmatrix(b,r2,c2);

    printf("\nMatrix A\n");
    Display(a,r1,c1);

    printf("\nMatrix B\n");
    Display(b,r2,c2);

    if(c1!=r2)
    {
        printf("\nMatrices can't be Multiplied\n");
    }
    else
    {
        printf("\nMatrix after Multiplication\n");
        matrixmult(a,b,c,r1,c2);
        Display(c,r1,c2);
    }

    return 0;
}