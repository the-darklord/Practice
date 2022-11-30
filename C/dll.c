#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *insert_beg(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	start->prev=new_node;
	new_node->prev=NULL;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start){
	struct node *new_node, *ptr;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;

	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}

void display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d", ptr->data);
}

int main()
{
	struct node *first=NULL;
	first->next=NULL;
	first->prev=NULL;
	first=insert_beg(first);
	first=insert_beg(first);
	first=insert_beg(first);
	first=insert_end(first);
	display(first);
	return 0;
}