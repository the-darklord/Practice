#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];

    printf("Enter first string : ");
    gets(s1);

    printf("Enter second string : ");
    gets(s2);

    strcat(s1,s2);

    printf("\n Concentated String is : \n");
    printf("%s",s1);

    return 0;
}