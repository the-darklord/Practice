#include <stdio.h>
#include <conio.h>

int fnSum(int a[],int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            sum+=a[i];
        }
    }
    return(sum);
}

int main()
{
    int a[100],n,i;

    printf("Enter Limit : \t");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element : \t");
        scanf("%d",&a[i]);
    }

    printf("Sum of Even Elements is : %d",fnSum(a,n));
    return 0;
}