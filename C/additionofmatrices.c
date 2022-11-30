#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j,m,n,p,q,w,x,g,h,a[100][100],b[100][100],c[100][100];

    printf("Enter Number of Rows of MATRIX A : \t");
    scanf("%d",&m);

    printf("Enter Number of Columns of MATRIX A : \t");
    scanf("%d",&n);

    printf("Enter Number of Rows of MATRIX B : \t");
    scanf("%d",&p);

    printf("Enter Number of Columns of MATRIX B : \t");
    scanf("%d",&q);

     if (m!=p || n!=q)
    {
        printf("\n");
        printf("Cannot Add the Given Matrices");
        printf("\n");
    }

    else
 {
        for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            w=i+1;
            x=j+1;
            printf("Enter the Element (%d,%d) of MATRIX A : \t",w,x);
            printf("\n");
            scanf("%d",&a[i][j]);
        }
        
    }

    

    for ( i = 0; i < p; i++)
    {
        for ( j = 0; j < q; j++)
        {
            w=i+1;
            x=j+1;
            printf("Enter the Element (%d,%d) of MATRIX B : \t",w,x);
            printf("\n");
            scanf("%d",&b[i][j]);
        }
        
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            c[i][j]=a[i][j] + b[i][j];
        }
    }
    
    printf("\n");
    printf("\n");
    printf("The Final MATRIX is \n ");
    printf("\n");
    printf("\n");

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d \t",c[i][j]);
        }
        printf("\n");
        printf("\n");
    }
    
    printf("\n");

 }
   
    return 0;

}