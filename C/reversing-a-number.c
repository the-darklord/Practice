#include <stdio.h>
#include <conio.h>

int main()
{
    int n,dig,rev;
    
    printf("Enter a Number : ");
    scanf("%d",&n);

    while (n!=0)
    {
        dig=n%10;
        rev=rev*10 + dig;
        n=n/10;
    }
    
    printf("The Reverse of Given Number is : %d",rev);
    return 0;
}