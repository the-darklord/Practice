#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct QUEUE
{
    int *queue;
    int size;
    int front,rear;
}QUEUE;

void insertcq(QUEUE *ptr,int x)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        ptr->front=ptr->rear=0;
        ptr->queue[ptr->rear]=x;
    }
    else if((ptr->rear+1)%ptr->size==ptr->front)
    {
        printf("QUEUE Full");
        exit(1);
    }
    else
    {
        ptr->rear=(ptr->rear+1)%ptr->size;
        ptr->queue[ptr->rear]=x;
    }
}

int deletecq(QUEUE *ptr)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        printf("QUEUE Empty");
        exit(1);
    }
    else if(ptr->rear+1==ptr->front)
    {
        int x=ptr->queue[ptr->front];
        ptr->front=ptr->rear=-1;
        return x;
    }
    else
    {
        int x=ptr->queue[ptr->front];
        ptr->front=(ptr->front+1)%ptr->size;
        return x;
    }
}

void displaycq(QUEUE *ptr)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
        printf("\nQUEUE EMPTY\n");
        exit(1);
    }
    printf("\nQUEUE CONTENTS : \n");
    if(ptr->front<=ptr->rear)
    {
        for(int i=ptr->front;i<=ptr->rear;i++)
        {
            printf("%d\t",ptr->queue[i]);
        }
    }
    else
    {
        for(int i=ptr->front;i<ptr->size;i++)
        {
            printf("%d\t",ptr->queue[i]);
        }
        for(int i=0;i<=ptr->rear;i++)
        {
            printf("%d\t",ptr->queue[i]);
        }
    }
    printf("\n");
}

void main()
{
    QUEUE q1,*ptr=&q1;
    int n;
    printf("Enter QUEUE Size : \t");
    scanf("%d",&n);
    ptr->size=n;
    ptr->front=ptr->rear=-1;
    ptr->queue=(int *)malloc(ptr->size*sizeof(int));
    insertcq(ptr,1);
    insertcq(ptr,3);
    insertcq(ptr,5);
    insertcq(ptr,2);
    displaycq(ptr);
    printf("DELETED ELEMENT : %d",deletecq(ptr));
    insertcq(ptr,9);
    displaycq(ptr);
}