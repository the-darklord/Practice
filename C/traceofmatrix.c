#include <stdio.h>
#include <conio.h>

int main()
{
    int m,n,i,j,w,z,sum,a[100][100];

    printf("Enter Number of Rows : ");
    scanf("%d",&m);

    printf("Enter Number of Columns : ");
    scanf("%d",&n);

    if (m==n)
    {
        for (i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
            {
                w=i+1;
                z=j+1;
                printf("Enter the Element : (%d,%d)",w,z);
                scanf("%d",&a[i][j]);
            }

        }

        for (i=0;i<m;i++)
        {
             sum=sum + a[i][i];
        }

        printf("The Trace of Matrix is : %d",sum);

    }
    else
    {
        printf("It is not a square Matrix");
    }
    
    return 0;

}