#include <stdio.h>
#include <conio.h>

int main()
{
    char string[100];
    int i,n=0,flag=0;

    printf("\n Enter String : \n");
    gets(string);

    for (i = 0;string[i]!='\0'; i++)
    {
        n++;
        for (i = 0; i < n/2; i++)
        {
            if (string[i]!=string[n-1-i])
            {
                flag=1;
                break;
            }
            
        }
        
    }
    
    if (flag==0)
      {
         printf("It is a Palindrome");
     }
      else
     {
          printf("It is not a Palindrome");
      }

        return 0;
}
    