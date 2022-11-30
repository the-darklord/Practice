#include <stdio.h>
#include <conio.h>

int main()
{
    int n, m;
    float p, t;
    char grade;

    printf("\n Enter Your Scored Marks : \n");
    scanf("%d",&n);

    printf("\n Enter Your Maximum Marks : \n");
    scanf("%d",&m);

    if (n>m || n<0)
    {
        printf("Incorrect Entry %d",n);
    }
    
    t=m/100;
    p=n/t;

    if (p>=90)
    {
        grade='A';
    }
    else
    {
        if (p>=80 && p<90)
        {
            grade='B';
        }
        else
        {
            if (p>=70 && p<80)
            {
                grade='C';
            }
            else
            {
                if (p>=60 && p<70)
                {
                    grade='D';
                }
                else
                {
                    if (p>=50 && p<60)
                    {
                        grade='E';
                    }
                    else
                    {
                        grade='F';
                    }
                    
                    
                }
                
            }
            
        }
        
    }
    

    printf("Your Grade is : %c",grade);
    return 0;
    
}