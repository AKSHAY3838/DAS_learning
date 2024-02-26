#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct BST
{
   int item;
   struct BST *llink, *rlink;
};
typedef struct BST* NODE;

NODE insert(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE search(NODE, int);
NODE Delete(NODE, int);

void main()
{
   int choice, key,n,i;
   NODE root = NULL, tmp, parent;

clrscr();

while(1)
   {
      printf("\n1.Create");
printf("\n2.Traverse the Tree in Preorder, Inorder, Postorder");
      printf("\n3.Search");
printf("\n4.Delete an element from the Tree");
      printf("\n5.Exit");
printf("\nEnter your choice :");
scanf("%d", &choice);

      switch (choice)
      {
	  case 1:   printf("\n enter the number of nodes");
		    scanf("%d",&n);
		    for(i=0;i<n;i++)
		  root = insert(root);
		  break;

	  case 2:if (root == NULL)
			printf("Tree Is Not Created");
		  else
		  {
			printf("\nThe Inorder display : ");
			inorder(root);
			printf("\nThe Preorder display : ");
			preorder(root);
			printf("\nThe Postorder display : ");
			postorder(root);
		  }
		  break;
	  case 3:printf("\nEnter Element to be searched :");
		scanf("%d", &key);
		  tmp = search(root, key);
		if(tmp == NULL)
			printf("Element does not exists\n");
		  else
			printf("\nThe element %d  found", tmp->item);
		  break;
	  case 4: printf("\nEnter Element to be deleted :");
		scanf("%d", &key);
		  root = Delete(root, key);
		  break;
	  default: exit(0);
      }
   }
}
/* This function is for creating a binary search tree */
NODE insert(NODE root)
{
   NODE temp, cur, prev;
   int item;
printf("\nEnter The Element ");
scanf("%d", &item);
   temp = (NODE) malloc(sizeof(struct BST));
   temp->llink = NULL;
   temp->rlink = NULL;
   temp->item = item;

   if (root == NULL)
	return temp;
   prev = NULL;
   cur = root;
while(cur != NULL)
   {
      prev = cur;
      if (item < cur-> item)
	 cur = cur->llink;
      else
	 cur = cur->rlink;
   }
   if (item < prev->item)
	 prev->llink = temp;
   else
	 prev->rlink = temp;
   return root;
}

/*  This function displays the tree in inorder fashion */
void inorder(NODE root)
{
   if (root != NULL)
   {
      inorder(root->llink);
printf("%d\t", root->item);
      inorder(root->rlink);
   }
}
/* This function displays the tree in preorder fashion */
void preorder(NODE root)
{
   if (root != NULL)
   {
printf("%d\t", root->item);
      preorder(root->llink);
      preorder(root->rlink);
   }
}
/* This function displays the tree in postorder fashion  */
void postorder(NODE root)
{
   if (root != NULL)
   {
      postorder(root->llink);
      postorder(root->rlink);
printf("%d\t", root->item);
   }
}
NODE search(NODE root, int key)
{
	NODE cur;
	if(root == NULL)
		return NULL;
	cur = root;
	while(cur != NULL)
	{
		if(key == cur->item)
			return cur;
		if(key<cur->item)
			cur = cur->llink;
		else
			cur = cur->rlink;
	}
	return NULL;
}
NODE Delete(NODE root, int data) 
{
	NODE temp;
	int min;

	if (root == NULL) 
	{
	     return NULL;
	}
	if (data < root->item) 
	{  // data is in the left sub tree.
		root->llink = Delete(root->llink, data);
	} 
	else if (data > root->item) 
	{ // data is in the right sub tree.
		root->rlink = Delete(root->rlink, data);
	} 
	else 
	{
	     // case 1: no children
	     if (root->llink == NULL && root->rlink == NULL) 
		{
		free(root); // wipe out the memory, in C, use free function
		        root = NULL;
		}
	     // case 2: one child (right)
	     else if (root->llink == NULL) 
		{
		        temp = root; // save current node as a backup
		        root = root->rlink;
		        free(temp);
		}
	     // case 3: one child (left)
	     else if (root->rlink == NULL) 
		{
		        temp = root; // save current node as a backup
		        root = root->llink;
		        free(temp);
	     }
	     // case 4: two children
	     else 
		{
		        min = FindMin(root->rlink); // find minimal value of right sub tree
		        root->item = min; // duplicate the node
		        root->rlink = Delete(root->rlink, min); // delete the duplicate node
	     }
	}
	return root; // parent node can update reference
}
int FindMin(NODE root) {
   if (root == NULL) {
      return -1; // or undefined.
   }
   if (root->llink != NULL) {
      return FindMin(root->llink); // left tree is smaller
   }
   return root->item;
}
