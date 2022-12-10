#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
struct node
{
    int data;
    Nodeptr next;
};

typedef struct STACK
{
    int data[100],top;
}STACK;

void push(STACK *ptr,int ele)
{
    ptr->data[++(ptr->top)]=ele;
}

int pop(STACK *ptr)
{
    return (ptr->data[(ptr->top)--]);
}

Nodeptr getnode()
{
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr InsertFirst(Nodeptr first,int data)
{
    Nodeptr rear=first,temp=getnode();
    temp->data=data;
    temp->next=first;
    if(first==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        while(rear->next!=first)
        {
            rear=rear->next;
        }
        rear->next=temp;
        return temp;
    }
}

Nodeptr InsertLast(Nodeptr first,int data)
{
    Nodeptr rear=first,temp=getnode();
    temp->data=data;
    temp->next=first;
    if(first==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        while(rear->next!=first)
        {
            rear=rear->next;
        }
        rear->next=temp;
        return first;
    }
}

Nodeptr Create(long int n)
{
    Nodeptr temp=NULL;
    int k;
    while(n>0)
    {
        k=n%10;
        temp=InsertFirst(temp,k);
        n=n/10;
    }
    return temp;
}

void Display(Nodeptr list)
{
    Nodeptr temp=list;
    while(temp->next!=list)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("%d \n",temp->data);
}

Nodeptr Multiply(Nodeptr root,int n)
{
    Nodeptr res=NULL;
    Nodeptr l=root,l1=NULL,l2=NULL;
    int k1,k2,v1,v2,c1=0,c2=0;
    k1=n%10;
    n=n/10;
    k2=n%10;

    STACK s,s1,s2,*p=&s,*p1=&s1,*p2=&s2;
    p->top=-1;
    p1->top=-1;
    p2->top=-1;
    
    while(l->next!=root)
    {
        push(p,l->data);
        l=l->next;
    }
    push(p,l->data);
    
    while(p->top!=-1)
    {
        int x = pop(p);
        v1=(x*k1)+c1;
        c1=v1/10;
        v1=v1%10;
        v2=(x*k2)+c2;
        c2=v2/10;
        v2=v2%10;
        l1=InsertFirst(l1,v1);
        l2=InsertFirst(l2,v2);
    }
    if(c1!=0)
    {
        l1=InsertFirst(l1,c1);
    }
    if(c2!=0)
    {
        l2=InsertFirst(l2,c2);
    }
    printf("\nIntermediate Lists are \n");
    l1=InsertFirst(l1,0);
    l2=InsertLast(l2,0);
    Display(l1);
    Display(l2);
    Nodeptr h1=l1,h2=l2;
    while(h1->next!=l1&&h2->next!=l2)
    {
        push(p1,h1->data);
        push(p2,h2->data);
        h1=h1->next;
        h2=h2->next;
    }
    push(p1,h1->data);
    push(p2,h2->data);
    int v,c=0;
    while(p1->top!=-1&&p2->top!=-1)
    {
        int x1=pop(p1),x2=pop(p2);
        v=x1+x2+c;
        c=v/10;
        v=v%10;
        res=InsertFirst(res,v);
    }
    if(c!=0)
    {
        res=InsertFirst(res,c);
    }
    return res;
}


void main()
{
    Nodeptr first=NULL;
    long int n;
    int m;
    printf("Enter a long int number : \t");
    scanf("%ld",&n);
    printf("Enter a 2 digit multiplier : \t");
    scanf("%d",&m);
    first=Create(n);
    printf("\nInitial List : ");
    Display(first);
    first=Multiply(first,m);
    printf("\nResult is : ");
    Display(first);
}