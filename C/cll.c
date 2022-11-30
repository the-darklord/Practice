//////////////SINGLY LINKED LISTS//////////////
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

//FUNCTION TO CREATE A LINKED LIST
struct node *create(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	new_node->next=NULL;
	start=new_node;
	return start;
}

//FUNCTION TO DISPLAY A LINKED LIST
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d", ptr->data);
	return start;
}

//FUNCTION TO ADD A NODE AT THE BEGINNING OF THE LINKED LIST
struct node *insert_beg(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	new_node->next=start;
	start=new_node;
	return start;
}

//FUNCTION TO ADD A NODE AT THE END OF THE LINKED LIST
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
	new_node->next=NULL;
	return start;
}

//FUNCTION TO ADD A NODE BEFORE THE GIVEN NODE
struct node *insert_before_given(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int data, val;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	printf("Enter the value before which node is added:\n");
	scanf("%d", &val);
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

//FUNCTION TO ADD A NODE AFTER THE GIVEN NODE
struct node *insert_after_given(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int data, val;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	printf("Enter the value after which node is added:\n");
	scanf("%d", &val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

//FUNCTION TO DELETE A NODE FROM THE BEGINNING
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr=start;
	start=ptr->next;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE FROM THE END
struct node *delete_end(struct node *start){
	struct node *ptr, *preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A GIVEN NODE
struct node *delete_given(struct node *start){
	struct node *ptr, *preptr;
	int val:
	printf("Enter value to delete:\n");
	scanf("%d", &val);

	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE AFTER A GIVEN NODE
struct node *delete_after_given(struct node *start){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value to delete:\n");
	scanf("%d", &val);

	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE BEFORE A GIVEN NODE
struct node *delete_before_given(struct node *start){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value to delete:\n");
	scanf("%d", &val);

	ptr=start;
	preptr=ptr;
	while(ptr->next->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}





//////////////CIRCULAR SINGLY LINKED LISTS//////////////
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

//FUNCTION TO CREATE A CIRCULAR LINKED LIST
struct node *create_cll(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	start=new_node;
	new_node->next=start;
	return start;
}

//FUNCTION DISPLAY A CIRCULAR LINKED LIST
struct node *display_cll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d->", ptr->data);
	return start;
}

//FUNCTION TO ADD A NODE AT THE BEGINNING OF THE CIRCULAR LINKED LIST
struct node *insert_beg_cll(struct node *start){
	struct node *new_node, *ptr;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;

	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}

//FUNCTION TO ADD A NODE AT THE END OF THE CIRCULAR LINKED LIST
struct node *insert_end_cll(struct node *start){
	struct node *new_node, *ptr;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;

	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	return start;
}

//FUNCTION TO DELETE A NODE AT THE BEGINNING OF THE CIRCULAR LINKED LIST
struct node *delete_beg_cll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}

//FUNCTION TO DELETE A NODE AT THE END OF THE CIRCULAR LINKED LIST
struct node *delete_end_cll(struct node *start){
	struct node *ptr, *preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *delete_after_given_cll(struct node *start){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value after whcih node is deleted:\n");
	scanf("%d", &val);

	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
		start=preptr->next;
	free(ptr);
	return start;
}

struct node *delete_entire_cll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		start=delete_end_cll(start);
	free(start);
	return start;
}





//////////////DOUBLY LINKED LISTS//////////////
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

//FUNCTION TO CREATE A DOUBLY LINKED LIST
struct node *create_dll(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	new_node->next=NULL;
	new_node->prev=NULL;
	start=new_node;
	return start;
}

//FUNCTION TO DISPLAY A DOUBLY LINKED LIST
struct node *display_dll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d", ptr->data);
	return start;
}

//FUNCTION TO ADD A NODE AT THE BEGINNING OF THE DOUBLY LINKED LIST
struct node *insert_beg_dll(struct node *start){
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

//FUNCTION TO ADD A NODE AT THE END OF THE DOUBLY LINKED LIST
struct node *insert_end_dll(struct node *start){
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

//FUNCTION TO ADD A NODE BEFORE THE GIVEN NODE IN THE DOUBLY LINKED LIST
struct node *insert_before_given_dll(struct node *start){
	struct node *new_node, *ptr;
	int data, val;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	printf("Enter the value before which data is inserted:\n");
	scanf("%d", &val);

	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	new_node->prev=ptr->prev;
	new_node->next=ptr;
	ptr->prev->next=new_node;
	ptr->prev=new_node;
	return start;
}

//FUNCTION TO ADD A NODE AFTER THE GIVEN NODE IN THE DOUBLY LINKED LIST
struct node *insert_after_given_dll(struct node *start){
	struct node *new_node, *ptr;
	int data, val;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", %data);
	new_node->data=data;
	printf("Enter the value after which data is inserted:\n");
	scanf("%d", &val);

	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	new_node->next=ptr->next;
	ptr->next->prev=new_node;
	ptr->next=new_node;
	new_node->prev=ptr;
	return start;
}

//FUNCTION TO DELETE A NODE AT THE END OF THE DOUBLY LINKED LIST
struct node *delete_end_dll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->prev->next=NULL;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE AT THE BEGINNING OF THE DOUBLY LINKED LIST
struct node *delete_beg_dll(struct node *start){
	struct node *ptr;
	ptr=start;
	start=ptr->next;
	start->prev=NULL;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE AFTER A GIVEN NODE OF THE DOUBLY LINKED LIST
struct node *delete_after_given_dll(struct node *start){
	struct node *ptr, *temp;
	int val;
	prinf("Enter the value after which node is deleted:\n");
	scanf("%d", &val);

	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
	return start;
}

//FUNCTION TO DELETE A NODE BEFORE A GIVEN NODE OF THE DOUBLY LINKED LIST
struct node *delete_before_given_dll(struct node *start){
	struct node *ptr, *temp;
	int val;
	printf("Enter the value before which node is deleted:\n");
	scanf("%d", &val);

	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	temp=ptr->prev;
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
	free(temp);
	return start;
}

//FUNCTION TO DELETE THE ENTIRE DOUBLY LINKED LIST
struct node *delete_entire_dll(struct node *start){
	while(start!=NULL)
		start=delete_end_dll(start);
	return start;
}





//////////////CIRCULAR DOUBLY LINKED LISTS//////////////
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

//FUNCTION TO CREATE A DOUBLY CIRCULAR LINKED LIST
struct node *create_cdll(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;
	new_node->prev=start;
	new_node->next=start;
	start=new_node;
	return start;
}

//FUNCTION TO DISPLAY A CIRCULAR LINKED LIST
struct node *display_cdll(struct node *start){
	struct node *ptr;
	prt=start;
	while(ptr->next!=start){
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d->", ptr->data);
	return start;
}

//FUNCTION TO ADD A NODE AT THE BEGINNING OF THE CIRCULAR DOUBLY LINKED LIST
struct node *insert_beg_cdll(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;

	new_node->next=start;
	start->prev->next=new_node;
	new_node->prev=start->prev;
	start->prev=new_node;
	start=new_node;
	return start;
}

//FUNCTION TO ADD A NODE AT THE BEGINNING OF THE CIRCULAR DOUBLY LINKED LIST
struct node *insert_end_cdll(struct node *start){
	struct node *new_node;
	int data;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d", &data);
	new_node->data=data;

	new_node->next=start;
	start->prev->next=new_node;
	new_node->prev=start->prev;
	start->prev=new_node;
	return start;
}

//FUNCTION TO DELETE A NODE AT THE BEGINNING OF THE CIRCULAR DOUBLY LINKED LIST
struct node *delete_beg_cdll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	start->next->prev=ptr;
	ptr=start;
	start=ptr->next;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A NODE AT THE END OF THE CIRCULAR DOUBLY LINKED LIST
struct node *delete_end_cdll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE A GIVEN NODE OF THE CIRCULAR DOUBLY LINKED LIST
struct node *delete_given_cdll(struct node *start){
	struct node *ptr;
	int val;
	printf("Enter the value to delete:\n");
	scanf("%d", &val);
	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	return start;
}

//FUNCTION TO DELETE ENTIRE CIRCULAR DOUBLY LINKED LIST
struct node *delete_entire_cdll(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		start=delete_end_cdll(start);
	free(ptr);
	return start;
}