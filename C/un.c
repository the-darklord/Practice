#include <stdio.h>

int main()
{
    int n,i,j,temp,a[100],num;
    printf("Number of Numbers : ");
    scanf("%d",&n);

    fflush(stdin);

    for (i=0;i<n;i++)
    {
        printf("Enter Numbers : ");
        scanf("%d",&a[i]);
    }

    fflush(stdin);

    printf("Enter '1' for Ascending Order , '2' for Descending Order : \t");
    scanf("%d",&num);

    switch(num)
    {
        case 1 :
            for (i=0;i<n-1;i++)
            {
                for (j=0;j<n-i-1;j++)
                {
                    if (a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                    
                }
            }
            printf("The Ascending Order is : \n");
            for (i=0;i<n;i++)
            {
                printf("%d \n",a[i]);
            }
            break;
        
        case 2 :
            for (i=0;i<n-1;i++)
                {
                    for (j=0;j<n-i-1;j++)
                    {
                        if (a[j]<a[j+1])
                        {
                            temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                        }
                        
                    }
                }
            printf("The Descending Order is : \n");
            for (i=0;i<n;i++)
            {
                printf("%d \n",a[i]);
            }
            break;

        default :
                printf("INVALID CASE");
                break;
    }
    
    
    return 0;
}