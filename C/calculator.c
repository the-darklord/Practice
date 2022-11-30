#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int o;
    float x,y,z;

    printf("List of Operators " );

    printf("\n 1.Addition \n 2.Substraction \n 3.Multiplication \n 4.Division \n 5.Inverse \n 6.Square \n 7.Square Root \n");

    printf("Enter the Value of Operator : ");
    scanf("%d",&o);

    switch (o)
    {
    case 1:
            printf("Enter value of X : ");
            scanf("%f",&x);

            printf("Enter value of Y : ");
            scanf("%f",&y);

            z=x+y;
        break;

    case 2:
            printf("Enter value of X : ");
            scanf("%f",&x);

            printf("Enter value of Y : ");
            scanf("%f",&y);

            z=x-y;
        break;

    case 3:
            printf("Enter value of X : ");
            scanf("%f",&x);

            printf("Enter value of Y : ");
            scanf("%f",&y);

            z=x*y;
        break;

    case 4:
            printf("Enter value of X : ");
            scanf("%f",&x);

            printf("Enter value of Y : ");
            scanf("%f",&y);

            z=x/y;
        break;

    case 5:
            printf("Enter value of X : ");
            scanf("%f",&x);

            z=1/x;
        break;

    case 6:
            printf("Enter value of X : ");
            scanf("%f",&x);

            z=x*x;
        break;

    case 7:
            printf("Enter value of X : ");
            scanf("%f",&x);

            z=sqrt(x);
        break;

    default:
        printf("\n Invalid Choice \n");
        break;
    }
            
    printf("\n Result is : %.2f \n",z);

    return 0;

}