#include <stdio.h>
#include <conio.h>

struct student
{
    int rollnum;
    char name[15];
    struct {
        int sub1;
        int sub2;
        int sub3;
    }marks;
};

struct student fs[3];

int main()
{
    int i,n,total[100],avg[100],tot;

    for(i=0;i<n;i++)
    {
        printf("Marks of %s in Sub1 : ",fs[i].name);
        scanf("%d",&fs[i].marks.sub1);

        printf("Marks of %s in Sub2 : ",fs[i].name);
        scanf("%d",&fs[i].marks.sub2);

        printf("Marks of %s in Sub3 : ",fs[i].name);
        scanf("%d",&fs[i].marks.sub3);
    }

    for(i=0;i<n;i++)
    {
        total[i]=fs[i].marks.sub1 + fs[i].marks.sub2 + fs[i].marks.sub3;
        avg[i]=total[i]/3;
    }

    printf("Total and Average of Each Student \n");
    for(i=0;i<n;i++);
    {
        printf("%s Total is %d , Average is %d",fs[i].name,total[i],avg[i]);
    }

    return 0;
}