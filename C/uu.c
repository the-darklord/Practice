#include <stdio.h>

int main()
{
    int a[500],i,limit,p;

    printf("Enter limit : \t");
    scanf("%d",&limit);

    for(i=0;i<limit;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<limit;i++)
    {
        p=limit-1-i;
        printf("%d \t",a[p]);
    }

    return 0;
}