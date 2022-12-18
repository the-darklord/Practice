#include <stdio.h>
#include <stdlib.h>

typedef struct node * Nodeptr;
struct node
{
    int data;
    Nodeptr lc;
    Nodeptr rc;
};

typedef struct
{
    Nodeptr stack[100];
    int top;
}STACK;

void push(STACK *ptr,Nodeptr item)
{
    ptr->stack[++ptr->top]=item;
}

Nodeptr pop(STACK *ptr)
{
    return ptr->stack[ptr->top--];
}

Nodeptr getnode()
{
    return ((Nodeptr)calloc(1,sizeof(struct node)));
}

Nodeptr Create_BT(int data)
{
    int x;
    if(data!=-1)
    {
        Nodeptr temp=getnode();
        temp->lc=temp->rc=NULL;
        temp->data=data;
        
        printf("Enter LeftChild of %d : ",data);
        scanf("%d",&x);
        temp->lc=Create_BT(x);
        
        printf("Enter RightChild of %d : ",data);
        scanf("%d",&x);
        temp->rc=Create_BT(x);
        
        return temp;
    }
    return NULL;
}

void inorder(Nodeptr root)
{
    if(root)
    {
        inorder(root->lc);
        printf("%d ",root->data);
        inorder(root->rc);
    }
}

void preorder(Nodeptr root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void postorder(Nodeptr root)
{
    if(root)
    {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d ",root->data);
    }
}

void iterative_inorder(Nodeptr root)
{
    Nodeptr cur=root;
    int done=0;
    STACK s1;
    s1.top=-1;
    if(!root)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    while(!done)
    {
        while(cur)
        {
            push(&s1,cur);
            cur=cur->lc;
        }
        if(s1.top!=-1)
        {
            cur=pop(&s1);
            printf("%d ",cur->data);
            cur=cur->rc;
        }
        else
        {
            done=1;
        }
    }
}

void iterative_preorder(Nodeptr root)
{
    STACK s1;
    s1.top=-1;
    if(!root)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    push(&s1,root);
    Nodeptr cur;
    while(s1.top!=-1)
    {
        cur=pop(&s1);
        printf("%d ",cur->data);
        if(cur->rc)
        {
            push(&s1,cur->rc);
        }
        if(cur->lc)
        {
            push(&s1,cur->lc);
        }
    }
}

void iterative_postorder(Nodeptr root)
{
    if(!root)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    STACK s1,s2;
    s1.top=-1;
    s2.top=-1;
    Nodeptr cur;
    push(&s1,root);
    while(s1.top!=-1)
    {
        cur=pop(&s1);
        push(&s2,cur);
        if(cur->lc)
        {
            push(&s1,cur->lc);
        }
        if(cur->rc)
        {
            push(&s1,cur->rc);
        }
    }
    while(s2.top!=-1)
    {
        cur=pop(&s2);
        printf("%d ",cur->data);
    }
}

void main()
{
    Nodeptr root=NULL;
    int x;
    printf("Enter Data of Root : \t");
    scanf("%d",&x);
    root=Create_BT(x);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPreorder : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\nIterative Inorder : ");
    iterative_inorder(root);
    printf("\nIterative Preorder : ");
    iterative_preorder(root);
    printf("\nIterative Postorder : ");
    iterative_postorder(root);
}