#include <stdio.h>
#include <conio.h>

void fibFn(int lim)
{
    int i,first,sec,next;
    if(lim<=0)
    {
    printf("Limit Should be Positive");
    }
    else
    {
        printf("Fibonacci Numbers are \n");
        first=0,sec=1;
        for(i=1;i<=lim;i++)
            {
                printf("%d \t",first);
                next=first+sec;
                first=sec;
                sec=next;
            }
    }
}

int main()
{
    int n;
    printf("Enter the limit : ");
    scanf("%d",&n);

    fibFn(n);
    return 0;
}