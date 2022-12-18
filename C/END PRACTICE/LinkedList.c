#include <stdio.h>
#include <stdlib.h>

//This is written for integer data type
//change the data types as you wish
//careful while using String

//Structure for SLL and Circular SLL

typedef struct node* Nodeptr;
struct node
{
    int data;
    Nodeptr next;
};

//Structure for DLL and Circular DLL 

typedef struct node* Nodeptr;
struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

//Memory Allocation is Same for all types of LL

Nodeptr getnode()
{
    return (Nodeptr)calloc(1,sizeof(struct node));
}

//SLL

//Insert Front in  SLL

Nodeptr InsF(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->next=NULL;
    if(root)
    {
        temp->next=root;
    }
    return temp;
}

//Insert Last in  SLL

Nodeptr InsL(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->next=NULL;
    if(root)
    {
        Nodeptr last=root;
        while(last->next)
        {
            last=last->next;
        }
        last->next=temp;
        return root;
    }
    return temp;
}

//Delete Front in SLL

int DelF(Nodeptr *root)
{
    Nodeptr temp=*root;
    int x = temp->data;
    *root=(*root)->next;
    temp->next=NULL;
    free(temp);
    return x;
}

//Delete Last in SLL

int DelL(Nodeptr *root)
{
    Nodeptr temp=*root,prev;
    while(temp->next)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    int x = temp->data;
    free(temp);
    return x;
}

//Displaying SLL

void Display(Nodeptr list)
{
    printf("\n");
    while(list)
    {
        printf("%d \t",list->data);
        list=list->next;
    }
    printf("\n");
}

//CSLL

//Insert Front in  CSLL

Nodeptr InsF(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
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

//Insert Last in  CSLL

Nodeptr InsL(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
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

//Delete Front in CSLL

int DelF(Nodeptr *root)
{
    Nodeptr temp=*root;
    while(temp->next!=*root)
    {
        temp=temp->next;
    }
    temp->next=(*root)->next;
    Nodeptr del=*root;
    int x = del->data;
    *root=(*root)->next;
    del->next=NULL;
    free(del);
    return x;
}

//Delete Last in CSLL

int DelL(Nodeptr *root)
{
    Nodeptr temp=*root,last;
    while(temp->next!=*root)
    {
        last=temp;
        temp=temp->next;
    }
    int x = temp->data;
    last->next=temp->next;
    temp->next=NULL;
    free(temp);
    return x;
}

//Displaying CSLL

void Display(Nodeptr list)
{
    printf("\n");
    Nodeptr temp=list;
    while(temp->next!=list)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

//DLL

//Insert Front in DLL

Nodeptr InsF(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->lchild=temp->rchild=NULL;
    if(root)
    {
        temp->rchild=root;
        root->lchild=temp;
        root=root->lchild;
        return root;
    }
    return temp;
}

//Insert Last in DLL

Nodeptr InsL(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->lchild=temp->rchild=NULL;
    if(root)
    {
        Nodeptr last=root;
        while(last->rchild)
        {
            last=last->rchild;
        }
        last->rchild=temp;
        temp->lchild=last;
        return root;
    }
    return temp;
}

//Delete Front in DLL

int DelF(Nodeptr *root)
{
    Nodeptr temp=*root;
    int x = temp->data;
    *root=(*root)->rchild;
    temp->rchild=NULL;
    (*root)->lchild=NULL;
    free(temp);
    return x;
}

//Delete Last in DLL

int DelL(Nodeptr *root)
{
    Nodeptr temp=*root,last;
    while(temp->rchild)
    {
        last=temp;
        temp=temp->rchild;
    }
    int x = temp->data;
    last->rchild=NULL;
    temp->lchild=NULL;
    free(temp);
    return x;
}

//Displaying DLL

void Display(Nodeptr list)
{
    printf("\n");
    while(list)
    {
        printf("%d \t",list->data);
        list=list->rchild;
    }
    printf("\n");
}

//CDLL

//Insert Front in CDLL

Nodeptr InsF(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->lchild=temp->rchild=temp;
    if(root)
    {
        Nodeptr last=root->lchild;
        last->rchild=temp;
        temp->lchild=last;
        temp->rchild=root;
        root->lchild=temp;
    }
    return temp;
}

//Insert Last in CDLL

Nodeptr InsL(Nodeptr root,int x)
{
    Nodeptr temp=getnode();
    temp->data=x;
    temp->lchild=temp->rchild=temp;
    if(root)
    {
        Nodeptr last=root->lchild;
        last->rchild=temp;
        temp->lchild=last;
        temp->rchild=root;
        root->lchild=temp;
        return root;
    }
    return temp;
}

//Delete Front in CDLL

int DelF(Nodeptr *root)
{
    Nodeptr last=(*root)->lchild;
    Nodeptr temp=*root;
    int x=temp->data;
    *root=(*root)->lchild;
    last->rchild=*root;
    (*root)->lchild=last;
    temp->lchild=temp->rchild=NULL;
    free(temp);
    return x;
}

//Delete Last in CDLL

int DelL(Nodeptr *root)
{
    Nodeptr temp=(*root)->lchild;
    Nodeptr last=last->lchild;
    int x=temp->data;
    last->rchild=*root;
    (*root)->lchild=last;
    temp->lchild=temp->rchild=NULL;
    free(temp);
    return x;
}

//Displaying CDLL

void Display(Nodeptr list)
{
    Nodeptr temp=list;
    printf("\n");
    while(temp->rchild!=list)
    {
        printf("%d\t",temp->data);
        temp=temp->rchild;
    }
    printf("%d\n",temp->data);
}

//Write main function as you desire 
//Don't Forget to comment out the structure and functions
//that are not required while compiling
//which may give errors

void main()
{
    Nodeptr root=NULL;
    root=InsF(root,5);
    root=InsF(root,6);
    root=InsL(root,4);
    Display(root);
    printf("DelF : %d \tDelL : %d",DelF(&root),DelL(&root));
    Display(root);
}