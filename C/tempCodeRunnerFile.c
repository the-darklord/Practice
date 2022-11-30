#include <stdio.h>

int main()
{
    int n,i,j,temp,a[100];
    char c;
    printf("Number of Numbers : ");
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        printf("Enter Numbers : ");
        scanf("%d",&a[i]);
    }

    fflush(stdin);

    printf("Enter 'a' for Ascending Order , 'd' for Descending Order : \t");
    scanf("%s",&c);

    switch(c)
    {
        case 'a' :
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
        
        case 'd' :
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