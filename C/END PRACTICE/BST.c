#include <stdio.h>
#include <stdlib.h>

typedef struct node * Nodeptr;
struct node
{
    int data;
    Nodeptr lc;
    Nodeptr rc;
};

Nodeptr getnode()
{
    return ((Nodeptr)calloc(1,sizeof(struct node)));
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

Nodeptr Insert_BST(Nodeptr root, int item)
{
    if (!root)
    {
        root = getnode();
        root->data= item;
        root->lc=root->rc = NULL;
        return root;
    }
    else
    {
        if (item<root->data)
            root->lc = Insert_BST(root->lc, item);
        else if (item>root->data)
            root->rc = Insert_BST(root->rc, item);
        else
            printf("Duplicates are not allowed\n");
        return root;
    }
}

Nodeptr Create_BST(Nodeptr root,int data)
{
    int x;
    root=getnode();
    root->data=data;
    root->lc=root->rc=NULL;
    while(1)
    {
        printf("Enter data to insert (-1 to exit) : \t");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        root=Insert_BST(root,x);
    }
    return root;
}

Nodeptr Search_BST(Nodeptr root,int key)
{
    if(!root)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return Search_BST(root->lc,key);
    }
    else
    {
        return Search_BST(root->rc,key);
    }
}

void main()
{
    Nodeptr root=NULL;
    int x;
    printf("Enter Data of Root : \t");
    scanf("%d",&x);
    root=Create_BST(root,x);
    inorder(root);
    Nodeptr search=Search_BST(root,12);
    if(search)
    {
        printf("\nFound %d",search->data);
    }
    else
    {
        printf("\nNot Found");
    }
}