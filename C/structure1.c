#include <stdio.h>
#include <conio.h>

void main()
{
    struct student
    {
        int rollnum;
        char name[20];
    };
    
   struct student student1;

    printf("Enter Student Roll Number : \t \n");
    scanf("%d",&student1.rollnum);

    printf("Enter Student Name : \t \n");
    scanf("%s",&student1.name);


    printf("Roll Number is : \t %d \n Name is : \t %s",student1.rollnum,student1.name);
    return 0;
}