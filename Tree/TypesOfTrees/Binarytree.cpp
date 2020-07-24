#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};

node* getnode(int data)
{
	node* newnode=new node();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* insertnode(node* root, int data)
{
	if(!root)
		root=getnode(data);
	else
	{
		node* temp;
		queue<node*>q;
		q.push(root);
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(!temp->left)
			{
				temp->left=getnode(data);
				break;
			}
			else
			{
				q.push(temp->left);
			}
			if(!temp->right)
			{
				temp->right=getnode(data);
				break;
			}
			else
			{
				q.push(temp->right);
			}
		}

	}
	return root;
}

void inorder(node* root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	node* root=NULL;
	root=insertnode(root,1);
	insertnode(root,2);
	insertnode(root,3);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,6);
	inorder(root);
	return 0;
}