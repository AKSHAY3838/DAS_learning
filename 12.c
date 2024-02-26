#include<stdio.h>
#include<stdlib.h>
FILE *fp;
struct employee
{
char name[20];
int key,salary;
}emp[20];
int n,m;
int *ht,index;
int count = 0;

void insert(int key)
{

	    index = key % m;
	    while(ht[index] != -1)
	    {
			printf("\ncollision detected for %d and resloved using linear probing",key);
			index = (index+1)%m;
	    }
	    ht[index] = key;
	    count++;
 }
void display()
{
	   int i;
	if(count == 0)
	  {
			printf("\nHash Table is empty");
			 return;
	   }

	printf("\nHash Table contents are:\n ");
	for(i=0; i<m; i++)
		printf("\n T[%d] --> %d ", i, ht[i]);
}
void main()
{
	 int i;
	clrscr();
	printf("\nEnter the number of employee  records (N) :   ");
	scanf("%d", &n);

	printf("\nEnter the two digit memory locations (m) for hash table:   ");
	scanf("%d", &m);

	 ht = (int *)malloc(m*sizeof(int));
	for(i=0; i<m; i++)
		     ht[i] = -1;
	fp=fopen("C:\\PROGRAM1.txt","w");
	printf("\nEnter the four digit key,name,salary values (K) for N Employee Records:\n  ");
	for(i=0; i<n; i++)
	 {
		    scanf("%d%s%d",&emp[i].key,&emp[i].name,&emp[i].salary);
		    fprintf(fp,"%d\t%s\t%d\n",emp[i].key,emp[i].name,emp[i].salary);
	 }
	 fclose(fp);
	  fp=fopen("C:\\PROGRAM1.txt","r");
	 for(i=0;i<n;i++)
	{
		if(count == m)
		   {
			printf("\n~~~Hash table is full. Cannot insert the record %d key~~~",i+1);
			break;
		   }
		   fscanf(fp,"%d",&emp[i].key);
		   insert(emp[i].key);

	}
	    fclose(fp);
	    //Displaying Keys inserted into hash table
	display();
getch();
}
