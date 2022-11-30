#include <stdio.h>
#include <conio.h>

int fnSum(int a[][100], int m, int n)
{
    int i,j,sum=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=a[i][j];
        }
    }

    return(sum);
}

int main()
{
    int a[100][100],m,n,i,j;

    printf("Enter the rows : ");
    scanf("%d",&m);

    printf("Enter the columns : ");
    scanf("%d",&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the element : \t");
            scanf("%d",&a[i][j]);
        }
    }

    printf("The Sum is : %d",fnSum(a,m,n));
    return 0;
}