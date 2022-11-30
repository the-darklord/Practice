#include <stdio.h>
#include <conio.h>

void Display1(void)
{
    printf("You have been promoted \n");
    printf("Welcome to Section 1 \n");
}

void Display2(void)
{
    printf("You have been promoted \n");
    printf("Welcome to Section 2 \n");
    Display1();
}

void Display3(void)
{
    printf("Welcome to Section 3 \n");
    Display2();
}

int main()
{
    int n;

    printf("Enter your section number : \t");
    scanf("%d",&n);

    switch (n)
    {
    case 3:
        Display3();
        break;
    
    default:
        printf("Invalid Input");
        break;
    }

    return 0;
}