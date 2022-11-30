#include <stdio.h>
#include <conio.h>

int main()
{
    int choice;
    printf("Enter your choice 1-yes , 2-no \n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("YES \n");
        break;
    
    case 2:
        printf("NO \n");
        break;

    default:
        printf("DEFAULT CASE \n");
        break;
    }

    printf("The Choice is %d",choice);
    return 0;

}