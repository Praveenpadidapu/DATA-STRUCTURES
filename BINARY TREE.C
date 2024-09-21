#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * create_node(int );
struct node * create_node(int d)
{
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp; 
}
struct node * insert(struct node *,int );
struct node * insert(struct node *root,int d)
{
	if(root==NULL)
	{
		return create_node(d);
	}
	if(d<root->data)
	{
		root->left=insert(root->left,d);
	}
	if(d>root->data)
	{
		root->right=insert(root->right,d);
	}
	return root;
}
void Inorder(struct node *);
void Inorder(struct node *root)
{
	if(root->left!=NULL)
	{
		Inorder(root->left);
	}
	printf("%4d",root->data);
	if(root->right!=NULL)
	{
		Inorder(root->right);	
	}
}
void Preorder(struct node *);
void Preorder(struct node *root)
{
	printf("%4d",root->data);
	if(root->left!=NULL)
	{
		Preorder(root->left);
	}
	if(root->right!=NULL)
	{
		Preorder(root->right);	
	}
}
void Postorder(struct node *);
void Postorder(struct node *root)
{
	if(root->left!=NULL)
	{
		Postorder(root->left);
	}
	if(root->right!=NULL)
	{
		Postorder(root->right);	
	}
	printf("%4d",root->data);
}
int main()
{
	struct node *root=NULL;
	root=insert(root,50);
	root=insert(root,20);
	root=insert(root,60);
	printf("Inorder-->");
	Inorder(root);
	printf("\n");
	printf("Preorder-->");
	Preorder(root);
	printf("\n");
	printf("Postorder-->");
	Postorder(root);
	printf("\n");
	return 0;
}
