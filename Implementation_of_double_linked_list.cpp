#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insert_first(int);
void insert_last(int);
void insert_position(int, int);
void delete_first();
void delete_last();
void delete_position(int);
void search(int);
void display_list();

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void insert_first(int x) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node *));
    if (head == NULL) {
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        printf("\nNode inserted @ First\n");
    } else {
        newnode->data = x;
        newnode->next = head;
        newnode->prev = NULL;
        head = newnode;
        printf("\nNode inserted @ First\n");
    }
    display_list();
}

void insert_last(int x) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node *));
    if (head == NULL) {
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        printf("\nNode inserted @ First & last\n");
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        printf("\nNode inserted @ Last\n");
    }
    display_list();
}
void insert_position(int x, int pos)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node*));
	struct node *temp=head;
	int i;
	if(pos==1)	//Insert an element as a first element
	{
		newnode->data=x;
		newnode->next= head;
		newnode->prev=NULL;
		head = newnode;
		printf("The Element  %d inserted successfully at the position:%d\n",x,pos);	}
	else
	{if(head==NULL)
		{		printf("\n...Invalid Position...\n");return;
		}
		else
		{
			for(i=0;i<pos-2;i++)
			{
				temp = temp->next;
			}
			if(temp==NULL)
			{
				printf("\n...cant insert...");
				return;
			}
			newnode->data = x;
			newnode->next = temp->next;
			newnode->prev=temp;
			temp->next->prev=newnode;
			temp->next = newnode;
			printf("\nThe Element %d inserted successfully at the position: %d\n",x,pos);
			return;
		}
	}
}
void delete_first()
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		struct node *temp;
		temp = head;
		head = temp->next;
		temp->next->prev=NULL;
		free(temp);
		printf("\n The First element is deleted from the linked list \n");
	}
	display_list();

}

void delete_last()
{
	struct node *temp1;
	temp1=head;
	if(head==NULL)
	{
		display_list();
		return;
	}
	else if(temp1->next==NULL)
	{                       
		free(temp1);
		printf("\nThe Last element is deleted from the linked list \n");
		display_list();
		return;
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->prev->next=NULL;		
		free(temp1);		//Last node is deleted
		printf("\n The Last element is deleted from the linked list \n");
		display_list();
		return;
	}
	
}

void delete_position(int pos)
{
	struct node *temp1, *temp2;
	int i;
	temp1 = head;
	if(head==NULL)
	{
		display_list();
		return;
	}
	else
	{
		if(pos==1)
		{
			head = temp1->next;
			temp1->next->prev=NULL;
			free(temp1);
			printf("\n The 1st position element is deleted....\n");
			display_list();
		}
		else
		{
			for(i=0; i<pos-2; i++)
			{temp1 = temp1->next;}
			if(temp1->next==NULL)
			{	printf("\n....Invalid Position....\n");
				return;			}
			temp2 = temp1->next;	//temp2 is desired positioned node to be deleted
			temp1->next = temp2->next;
			temp2->next->prev = temp1;
			free(temp2);		
			printf("\n The %d position element is deleted....\n",pos);
			display_list();}}}
void search(int val)
{   struct node *temp=head;
	int position=1, flag;
	if(head==NULL)
	{display_list();}
	else
	{		while(temp!=NULL)		//Don t use temp->next != null
		{	if(temp->data==val)
			{   printf("Element %d  present in the position: %d", val, position);
				flag = 0;}
			else	{flag=1;}
			temp = temp->next;
			position++;
					}
		if(flag==1)
			printf("The Element: %d Not found\n", val);}
	return;}
void display_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\n....THE LIST IS EMPTY...\n");
		return;	//Exit from display_list()
	}
	else
	{	temp=head;
		printf("\nThe elements present in the list are:\n");
		printf("Head");
		while(temp!=NULL)
		{
			printf("->%d", temp->data);	//print the elements
			temp = temp->next;
		}
	}
}
int main() {
    int ch, pos, val, pls, x;
    do {
        printf("Operations on List..\n");
        printf("1. Insertion\n2. Deletion\n3. Display list\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("1. Insertion at First\n");
                printf("2. Insertion at Last\n");
                printf("3. Insertion at specified position\n");
                printf("Enter your choice: ");
                scanf("%d", &pls);

                switch (pls) {
                    case 1:
                        printf("Enter the value to insert: ");
                        scanf("%d", &val);
                        insert_first(val);
                        break;

                    case 2:
                        printf("Enter the value to insert: ");
                        scanf("%d", &val);
                        insert_last(val);
                        break;

                    case 3:
                        display_list();
                        printf("Enter the value to insert: ");
                        scanf("%d", &val);
                        printf("Enter the position: ");
                        scanf("%d", &pos);
                        insert_position(val, pos);
                        break;

                    default:
                        printf("The choice is invalid\n");
                }
                break;

            case 2:
                display_list();
                printf("1. Delete the first element\n");
                printf("2. Delete the last element\n");
                printf("3. Enter the position to delete\n");
                printf("Enter your choice: ");
                scanf("%d", &pls);

                switch (pls) {
                    case 1:
                        delete_first();
                        break;

                    case 2:
                        delete_last();
                        break;

                    case 3:
                        display_list();
                        printf("Enter the position to delete: ");
                        scanf("%d", &pos);
                        delete_position(pos);
                        break;

                    default:
                        printf("The option is invalid...\n");
                        break;
                }
                break;

            case 3:
                display_list();
                break;

            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &val);
                search(val);
                getch();
                break;

            case 5:
                exit(1);

            default:
                printf("The option is invalid...\n");
        }

        getch();
    } while (ch != 5);

    getch();
    return 0;
}
