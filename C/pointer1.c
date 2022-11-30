#include <stdio.h>
#include <conio.h>

int main()
{
    int quantity;
    int *p=&quantity;

    printf("Enter a number : \t");
    scanf("%d",&quantity);

    printf("%x \n",&quantity);
    printf("%d \n",*p);

    return 0;
}