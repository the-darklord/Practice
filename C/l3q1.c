#include <stdio.h>
struct Complex
{
    int a,b;
};
void Display(struct Complex h)
{
    int t=h.b;
    char c='+';
    if(h.b<0)
    {
        t=-h.b;
        c='+';
    }
    printf("\n %d%c%di",h.a,c,t);
}
struct Complex Add(struct Complex c1,struct Complex c2,struct Complex add)
{
    add.a = c1.a + c2.a;
    add.b = c1.b + c2.b;
    return add;
}
struct Complex Sub(struct Complex c1,struct Complex c2,struct Complex sub)
{
    sub.a = c1.a - c2.a;
    sub.b = c1.b - c2.b;
    return sub;
}
struct Complex Mult(struct Complex c1,struct Complex c2,struct Complex mult)
{
    mult.a = ((c1.a*c2.a) - (c1.b*c2.b));
    mult.b = ((c1.a*c2.b) + (c1.b*c2.a));
    return mult;
}
int main()
{
    struct Complex c1,c2,add,sub,mult;
    printf("Enter real and imaginary parts of complex number 1 : \t");
    scanf("%d %d",&c1.a,&c1.b);
    printf("Enter real and imaginary parts of complex number 2 : \t");
    scanf("%d %d",&c2.a,&c2.b);
    printf("Entered Complex Numbers are \n");
    Display(c1);
    Display(c2);
    add=Add(c1,c2,add);
    printf("\nSum is ");
    Display(add);
    sub=Sub(c1,c2,sub);
    printf("\nDifference is ");
    Display(sub);
    mult=Mult(c1,c2,mult);
    printf("\nMultiplication is ");
    Display(mult);
    return 0;
}