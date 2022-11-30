#include <stdio.h>
#include <conio.h>

int main()
{
    char string[100];
    int i;

    printf("\n Enter String : \n");
    gets(string);

    for (i=0;string[i]!='\0';i++)
    {
        if (string[i]>='A' && string[i]<='Z')
        {
            string[i]+=32;
        }
        else if (string[i]>='a' && string[i]<='z')
        {
            string[i]-=32;
        }
        
    }
    
    printf("Modified String is : ");
    puts(string);
    return 0;

}