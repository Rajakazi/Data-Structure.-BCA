#include<stdio.h>
#include<stdlib.h>
int main()
{
//step 1: Creating structure:
struct node
{
int data;
struct node *next;
};
struct node *head, *newnode, *temp;
head=0;
int choice;
do
{
//step 2: creating node using using malloc( ) function
newnode=(struct node *) malloc(sizeof(struct node));
//step 3: Ask user to insert value
printf("enter the number to insert: ");
scanf("%d",&newnode->data);
newnode->next=0;
if(head==0)
{
head=newnode;
temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
printf("Do you want to continue(0=Exit,1=Continue)?");
scanf("%d",&choice);
}while(choice);
temp=head; //to display node from first entry, temp was stored address of last node
printf(" %p\n",head); //to print address of HEAD
while(temp!=0)
{
printf("[%d | %p]\n",temp->data, temp->next);
temp=temp->next;
}
getch();
return 0;
}