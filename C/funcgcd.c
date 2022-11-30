#include <stdio.h>
#include <conio.h>

int gcd(int x,int y)
{
    if(x==0)
    {
        return(y);
    }
    if(y==0)
    {
        return(x);
    }

    return gcd(y,x%y);
}

int main()
{
    int x,y;

    printf("Enter First Number : \t");
    scanf("%d",&x);

    printf("Enter Second Number : \t");
    scanf("%d",&y);

    printf("The GCD of Given Numbers is : \t %d",gcd(x,y));
    return 0;

}