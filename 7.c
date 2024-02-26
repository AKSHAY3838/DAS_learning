#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

struct node
{
	int sem,phno;
	char name[20],branch[20],usn[10];
	struct node *next;
}*first=NULL,*last=NULL,*temp=NULL,*temp1=NULL;

void create()
{
	int sem,phno;
	char name[20],usn[10],branch[20];
	temp=(struct node *)malloc(sizeof(struct node));

	printf("Enter the details \n");
	printf("\nName:"); scanf("%s",name); flushall();
	printf("\nUSN:"); gets(usn);   flushall();
	printf("\nBranch:"); gets(branch);
	printf("\nSem:"); scanf("%d",&sem);
	printf("\nPhone Number:"); scanf("%d",&phno);

	strcpy(temp->usn,usn);
	strcpy(temp->name,name);
	strcpy(temp->branch,branch);
	temp->sem=sem;
	temp->phno=phno;
	temp->next=NULL;

	count++;
}
void deletefront()
{
	temp=first;
	if(first==NULL)
	{
		printf("\n list is empty");
		return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted node is \n");
		printf("%s\t%s\t%s\t%d\t%d",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
		free(temp);
		first=NULL;
	}
	else
	{
		first=temp->next;
		printf("The deleted node is \n");
		printf("%s\t%s\t%s\t%d\t%d",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
		free(temp);
	}
	count--;
}
void deleteatend()
{
	temp=first;
	if(first==NULL)
	{
		printf("\n list is empty");
		 return;
	}
	if(temp->next==NULL)
	{
		printf("The deleted node is \n");
		printf("%s\t%s\t%s\t%d\t%d",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
		free(temp);
		first=NULL;
	}
	else
	{
		while(temp->next!=last)
			temp=temp->next;
		printf("The deleted node is \n");
		printf("%s\t%s\t%s\t%d\t%d",last->name,last->usn,last->branch,last->sem,last->phno);
		free(last);
		last=temp;
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
		last=temp;
	}
}
void display()
{
	if(first==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=first;
		printf("The node is \n");
		while(temp!=NULL)
		{

			printf("%s\t%s\t%s\t%d\t%d--->",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
			temp=temp->next;
			//printf("\n");
		}
	}
}
void main()
{
	int ch,i,n;
	clrscr();
	while(1)
	{
		printf("\n1.Insert n details student ");
		printf("\n2.Insert at beginning");
		printf("\n3.Insert at last");
		printf("\n4.Delete from begining");
		printf("\n5.Delete from last");
		printf("\n6.Display");
		printf("\n7.Exit");
		printf("\nEneter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("\nEnter the value of n ");
				scanf("%d",&n);
				   for(i=0;i<n;i++)
				insertatfirst();
				   break;
			  case 2 : insertatfirst();
				   break;
			  case 3 : insertatlast();
				   break;
			  case 4 : deletefront();
				   break;
			  case 5 : deleteatend();
				   break;
			  case 6 : display();
				   break;
			  case 7 : exit(1);
			  default: printf("\n Wrong Input, try again");
		}
	}
}

