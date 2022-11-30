#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j,m,n,b,c,a[100][100];

    printf("Enter Number of Rows : \t");
    scanf("%d",&m);

    printf("Enter Number of Columns : \t");
    scanf("%d",&n);

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
    return 0;

}