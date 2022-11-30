#include <stdio.h>
#include <conio.h>

int Trace(int a[][100],int n)
{
    int i,sum=0;

    for(i=0;i<n;i++)
    {
        sum+=a[i][i];
    }

    return(sum);
}

    int main()
{
    int i,j,m,n,b,c,temp,a[100][100];

    printf("Enter Number of Rows : \t");
    scanf("%d",&m);

    printf("Enter Number of Columns : \t");
    scanf("%d",&n);

if(m==n)
{
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            b=i+1;
            c=j+1;
            printf("Enter the Element (%d,%d) : \t",b,c);
            printf("\n");
            scanf("%d",&a[i][j]);
        }
        
    }
    
    printf("\n");
    printf("\n");
    printf("The MATRIX is \n ");
    printf("\n");
    printf("\n");

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d \t",a[i][j]);

        }
        printf("\n");
        printf("\n");
    }
    
    printf("\n");

    printf("The Trace of Given Matrix is : %d",Trace(a,n));

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
                { 
                    a[i][j]=Trace(a,n);
                }
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
            printf("%d \t",a[i][j]);

        }
        printf("\n");
        printf("\n");
    }
    
    printf("\n");

}
else
{
    printf("Invalid Inputs");
}

    return 0;

}