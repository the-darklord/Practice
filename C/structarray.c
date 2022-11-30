#include <stdio.h>
#include <conio.h>

struct StudentInfo
{
    int rollnum;
    char name,gender,place;
};

int main()
{
    int i,n;
    char mention;
    struct StudentInfo student[100];

    printf("Enter Number of Students : \t");
    scanf("%d",&n);

    printf("Enter Student Info \n");

    for(i=0;i<n;i++);
    {
        printf("\n Enter Name of Student %d : \t",i+1);
        scanf("%s",&student[i].name);

        printf("\n Enter Roll Number of Student %d : \t",i+1);
        scanf("%d",&student[i].rollnum);

        printf("\n Enter Gender (M/F) of Student %d : \t",i+1);
        scanf("%s",&student[i].gender);

        printf("\n Enter Place of Student %d : \t",i+1);
        scanf("%s",&student[i].place);
    }

    switch (student->gender)
    {
    case 'M':
        mention='Mr.';
        break;
    
    case 'F':
        mention='Miss.';
        break;

    default:
        break;
    }

    for(i=0;i<n;i++)
    {
        printf("\n The Info of Student %d is : \n",i+1);

        printf("\n Name is \t %s %s \n",mention,student[i].name);
        printf("\n Roll Number is \t %d \n",student[i].rollnum);
        printf("\n Place is \t %s \n",student[i].place);

    }
    
    return 0;
}