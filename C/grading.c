#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    char grade;

    printf("Enter Your Marks out of 100 : \n");
    scanf("%d",&n);

    if (n>=90)
    {
        grade='A';
    }
    
    if (n>=80 && n<=90)
    {
        grade='B';
    }
    
    if (n>=70 && n<=80)
    {
        grade='C';
    }

    if (n>=60 && n<=70)
    {
        grade='D';
    }

    if (n>=50 && n<=60)
    {
        grade='E';
    }

    if (n<=50)
    {
        grade='F';
    }

    printf("Your Grade is : %c",grade);
    return 0;

}