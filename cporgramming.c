#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/* Structure of a node */
struct node {
int data; // Data
struct node *next; // Address
};
struct node *head;
void createList(int n);
void insertNodeAtEnd(int data);
void displayList();
void main() {
int n, data;
clrscr();
printf("Enter the total number of nodes: ");
scanf("%d", &n);
createList(n);
printf("\nData in the list\n");

displayList();
insertNodeAtEnd(data);
printf("\nData in the list\n");

displayList(); }
void createList(int n) {
struct node *newNode, *temp;
int i;
head=0;
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data of node 1: ");
scanf("%d", &newNode
->data);

newNode
->next = 0; // Link address field to NULL
if(head==0) { head=temp=newNode; }
else {
temp
->next=newNode;
temp=newNode;
}
//Create n nodes and adds to linked list
for(i=2; i<=n; i++)
{
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data of node %d: ", i);
scanf("%d", &newNode->data);
newNode->next = 0; // Link address field of newNode with NULL
temp->next = newNode; // Link temp to the newNode
temp = newNode;
}
printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}
void insertNodeAtEnd(int data)
{
struct node *newnode, *temp;
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter data to insert at the END:");
scanf("%d",&newnode->data);
newnode->next=0;
temp=head;
while(temp->next!=0)
{
temp=temp->next;
}
temp->next=newnode;
printf("DATA INSERTED SUCCESSFULLY\n");
}
void displayList()
{
struct node *temp;
temp = head;
while(temp != NULL)
{
printf("Data = %d\n", temp->data); // Print data of current node
temp = temp->next; // Move to next node
}
getch();
}