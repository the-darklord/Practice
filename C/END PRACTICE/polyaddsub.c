#include <stdio.h>
#include <stdlib.h>


typedef struct node* Nodeptr;
struct node
{
    int coef,expon;
    Nodeptr next;
};

Nodeptr getnode()
{
    return (Nodeptr)calloc(1,sizeof(struct node));
}

Nodeptr InsF(Nodeptr root,int coef,int expon)
{
    Nodeptr temp=getnode();
    temp->coef=coef;
    temp->expon=expon;
    temp->next=temp;
    if(root)
    {
        Nodeptr last=root;
        while(last->next!=root)
        {
            last=last->next;
        }
        last->next=temp;
        temp->next=root;
    }
    return temp;
}


Nodeptr InsL(Nodeptr root,int coef,int expon)
{
    Nodeptr temp=getnode();
    temp->coef=coef;
    temp->expon=expon;
    temp->next=temp;
    if(root)
    {
        Nodeptr last=root;
        while(last->next!=root)
        {
            last=last->next;
        }
        last->next=temp;
        temp->next=root;
        return root;
    }
    return temp;
}

void Display(Nodeptr list)
{
    printf("\n");
    Nodeptr temp=list->next;
    while(temp!=list)
    {
        printf("%dx^%d",temp->coef,temp->expon);
        if(temp->next!=list)
        {
            printf(" + ");
        }
        temp=temp->next;
    }
    printf("\n");
}

Nodeptr CreatePoly(Nodeptr Poly)
{
    int c,e;
    while(1)
    {
        printf("Enter Coefficient and  Exponent \t(Enter -1 for Exponent to exit) : \n");
        scanf("%d %d",&c,&e);
        if(e==-1)
        {
            break;
        }
        Poly=InsL(Poly,c,e);
    }
    return Poly;
}

int Compare_Expon(int a,int b)
{
    if(a==b)
    {
        return 0;
    }
    else if(a>b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

Nodeptr Poly_Add(Nodeptr A,Nodeptr B)
{
    Nodeptr pA=A->next,pB=B->next,res=getnode();
    res->next=res;
    int c,e;
    while(pA!=A&&pB!=B)
    {
        if(Compare_Expon(pA->expon,pB->expon)==0)
        {
            c=pA->coef+pB->coef;
            e=pA->expon;
            pA=pA->next;
            pB=pB->next;
        }
        else if(Compare_Expon(pA->expon,pB->expon)==1)
        {
            c=pA->coef;
            e=pA->expon;
            pA=pA->next;
        }
        else
        {
            c=pB->coef;
            e=pB->expon;
            pB=pB->next;
        }
        if(c!=0)
        {
            res=InsL(res,c,e);
        }
    }
    while(pA!=A)
    {
        res=InsL(res,pA->coef,pA->expon);
        pA=pA->next;
    }
    while(pB!=B)
    {
        res=InsL(res,pB->coef,pB->expon);
        pB=pB->next;
    }
    return res;
}

Nodeptr Poly_Sub(Nodeptr A,Nodeptr B)
{
    Nodeptr pA=A->next,pB=B->next,res=getnode();
    res->next=res;
    int c,e;
    while(pA!=A&&pB!=B)
    {
        if(Compare_Expon(pA->expon,pB->expon)==0)
        {
            c=pA->coef-pB->coef;
            e=pA->expon;
            pA=pA->next;
            pB=pB->next;
        }
        else if(Compare_Expon(pA->expon,pB->expon)==1)
        {
            c=pA->coef;
            e=pA->expon;
            pA=pA->next;
        }
        else
        {
            c=-pB->coef;
            e=pB->expon;
            pB=pB->next;
        }
        if(c!=0)
        {
            res=InsL(res,c,e);
        }
    }
    while(pA!=A)
    {
        res=InsL(res,pA->coef,pA->expon);
        pA=pA->next;
    }
    while(pB!=B)
    {
        res=InsL(res,pB->coef,-pB->expon);
        pB=pB->next;
    }
    return res;
}


void main()
{
    printf("Enter Polynomial 1 : \n");
    Nodeptr Poly1=getnode();
    Poly1->next=Poly1;
    Poly1=CreatePoly(Poly1);
    printf("\nEnter Polynomial 2 : \n");
    Nodeptr Poly2=getnode();
    Poly2->next=Poly2;
    Poly2=CreatePoly(Poly2);
    Display(Poly1);
    Display(Poly2);
    Nodeptr add = Poly_Add(Poly1,Poly2);
    Display(add);
    Nodeptr sub = Poly_Sub(Poly1,Poly2);
    Display(sub);
}