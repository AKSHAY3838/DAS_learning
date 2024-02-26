#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
struct node
{
	struct node *prev;
	int ssn;
	long int phno;
	char name[20],dept[20],desg[10];
	float sal;
	struct node *next;
}*first=NULL,*last=NULL,*temp=NULL,*temp1=NULL;

void create()
{
	int ssn;
	long int phno;
	char name[20],dept[20],desg[10];
	float sal;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the employee details: ssn,name,dept,desg,sal,phno");
	scanf("%d%s%s%s%f%ld",&ssn,name,dept,desg,&sal,&phno);
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	strcpy(temp->desg,desg);
	temp->ssn=ssn;
	temp->sal=sal;
	temp->phno=phno;
	temp->prev=NULL;
	temp->next=NULL;
	count++;
}
void deleteatfirst()
{
	temp=first;
	if(first==NULL)
	{
		printf("\n DLL is empty");
		return;
	}
	if(temp->next==NULL)
	{
		printf("\nDeleted node is:");
		printf("%d\t%s\t%s\t%s\t%f\t%ld",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
		free(temp);
		first=NULL;
	}
	else
	{
		first=temp->next;
		printf("\nDeleted node is:");
		printf("%d\t%s\t%s\t%s\t%f\t%ld",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
		free(temp);
		first->prev=NULL;
	}
	count--;
}
void deleteatlast()
{
	temp=first;
	if(first==NULL)   	{
		printf("\n DLL is empty");
		return;
	}
	if(temp->next==NULL)
	{
		printf("\nDeleted node is:");
		printf("%d\t%s\t%s\t%s\t%f\t%ld",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
		free(temp);
		first=NULL;
	}
	else
	{
		printf("\nThe deleted node is:");
		temp1=last->prev;
		printf("%d\t%s\t%s\t%s\t%d\t%ld",last->ssn,last->name,last->dept,last->desg,last->sal,last->phno);
		free(last);
		last=temp1;
		last->next=NULL;
	}
	count--;
}
void insertatfirst()
{
	create();
	if(first==NULL)
	{
		
		first=temp;
		last=first;
	}
	else
	{
		
		first->prev=temp;
		temp->next=first;
		first=temp;
	}
}

void insertatlast()
{
	create();
	if(first==NULL)
	{
		first=temp;
		last=first;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void display()
{
	if(first==NULL)
	{
		printf("\nDLL is empty.");
		return;
	}
	else
	{
		temp=first;
		printf("\n DLL is\n");
		while(temp!=NULL)
		{

			printf("%d\t%s\t%s\t%s\t%f\t%ld\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
			temp=temp->next;
		}
		printf("\nThe number of nodes in the linked list is %d.",count);
	}
}
void main()
{
	int ch,i,n;
	clrscr();
	while(1)
	{
		printf("\nEnter the details:");
		printf("\n1.Enter n employee details.");
		printf("\n2.Insert at beginning.");
		printf("\n3.Insert at last");
		printf("\n4.Delete at beginning");
		printf("\n5.Delete at last");
		printf("\n6.Display");
		printf("\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter n value:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
					insertatlast();
				break;
			case 2:insertatfirst();
				break;
			case 3:insertatlast();
				break;
			case 4:deleteatfirst();
				break;
			case 5:deleteatlast();
				break;
			case 6:display();
				break;
			case 7:exit(1);
			default:printf("Invalid input.");
		}
	}
}
