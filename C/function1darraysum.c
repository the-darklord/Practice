#include <stdio.h>
#include <conio.h>

int fnSum(int a[], int n)
{
    int sum=0,i;
    for (i=0;i<n;i++)
    {
        sum+=a[i];
    }

    return(sum);
}

int main()
{
    int n,i,a[100];
    printf("Enter the limit : \t");
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        printf("Enter the element : \t");
        scanf("%d",&a[i]);
    }

    printf("The Sum is %d",fnSum(a,n));
    return 0;
}