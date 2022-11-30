#include <stdio.h>
#include <stdlib.h>

typedef struct node * Nodeptr;
struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

Nodeptr getnode()
{
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr create_BT(Nodeptr root,int data)
{
    int x;
    if(data!=-1)
    {
        Nodeptr temp=getnode();
        temp->data=data;

        printf("\nEnter lchild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->lchild=create_BT(temp->lchild,x);

        printf("\nEnter rchild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->rchild=create_BT(temp->rchild,x);
        return temp;
    }
    return NULL;
}

Nodeptr insert_BST(Nodeptr root, int item){
    if (root==NULL)
    {
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    else
    {
        if (item<root->data)
            root->lchild = CreateBST(root->lchild, item);
        else
        {
            if (item>root->data)
                root->rchild = CreateBST(root->rchild, item);
            else
                printf("Duplicates are not allowed\n");
        }
        return root;
    }
}

Nodeptr create_BST(Nodeptr root)
{
    int x;
    printf("\nEnter Root Data : \t");
    scanf("%d",&x);
}

void inorder(Nodeptr root)
{
    if(root)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void preorder(Nodeptr root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(Nodeptr root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}

void main()
{
    Nodeptr root=NULL;
    root=create_BST(root,x);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPreorder : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
}