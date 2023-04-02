#include <stdio.h>

void main()
{
    int m,n;
    printf("Enter 2 numbers : \t");
    scanf("%d %d",&m,&n);
    int t=m>n?n:m;
    while(t>0)
    {
        if(m%t==0&&n%t==0)
        {
            break;
        }
        t--;
    }
    printf("\nGCD is %d\n\n",t);
}