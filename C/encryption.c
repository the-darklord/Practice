#include <stdio.h>
#include <conio.h>

int main()
{
    char string[100];
    int i,n;

    printf("\n Enter Plaintext : \n");
    gets(string);

    printf("Enter the Key : \t");
    scanf("%d",&n);

    for (i=0;string[i]!='\0';i++)
    {
        string[i]=string[i]+n;
    }
    
    printf("Cypher Text is : ");
    puts(string);
    return 0;
}
