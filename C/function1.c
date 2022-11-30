#include <stdio.h>

void Display(void)
{
    printf("Hi from Display \n");
}

int main()
{
    printf("Hi from main \n");
    Display();
    printf("Bye Bye \n");
    return 0;
}