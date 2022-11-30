#include <stdio.h>
#include <conio.h>

int main()
{
    int a,b,c,greater;
    
    printf("Enter First Number : \n");
    scanf("%d",&a);

    printf("Enter Second Number : \n");
    scanf("%d",&b);

    printf("Enter Third Number : \n");
    scanf("%d",&c);
    
    if (a>b)
    {
        if (a>c)
        {
            greater=a;
        }
        else
        {
            greater=c;
        }
    }

    else
    {
        if (b>c)
        {
            greater=b;
        }
        else
        {
            greater=c;
        }
        
    }

    printf("The Greatest of given numbers is : %d",greater);

    return 0;
}