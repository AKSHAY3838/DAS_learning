#include<stdio.h>
#include<stdlib.h>

int n,a[10][10],i,j,source,s[10],reach[10],choice,count=0;

void bfs(int n,int a[10][10],int source,int s[])	//BFS Algorithm
{
	int q[10],u;
	int front=1,rear=1;
	s[source]=1;
	q[rear]=source;
	while(front<=rear)
	{
		u=q[front];
		front=front+1;
		for(i=1;i<=n;i++)
		if(a[u][i]==1 &&s[i]==0)
		{	rear=rear+1;
			q[rear]=i;
			s[i]=1;
		}
	}
}
void dfs(int v)	//DFS Algorithm
{
int i;
reach[v]=1;
for(i=1;i<=n;i++)
{
if(a[v][i] && !reach[i])
{
printf("\n %d->%d",v,i);
count++;
dfs(i);
}
}
}
int main()
{
	clrscr();
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)	//Provide matrix of 0’s and 1’s
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	while(1)
	{
printf("\nEnter your choice\n");
printf("1.BFS\n 2.DFS\n 3.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: 	printf("\n Enter the source :");
				scanf("%d",&source);	//Provide source for BFS
				for(i=1;i<=n;i++)
					s[i]=0;
				bfs(n,a,source,s);
				for(i=1;i<=n;i++)
				{
					if(s[i]==0)
						printf("\n The node %d is not reachable",i);
					else
						printf("\n The node %d is reachable",i);
				  }	
break;
case 2: dfs(1);
if(count==n-1)
					printf("\nThe graph is connected.");
				else
					printf("\nThe graph is not connected.");
           break;
case 3: exit(0);
}
}
}
