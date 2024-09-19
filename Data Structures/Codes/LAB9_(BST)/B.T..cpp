#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *right,*left;
		node(int data){
			this->data=data;
			this->right=NULL;
			this->left=NULL;
		}
};
class BST{
	public:
		node* addnode(int data){
			node *newnode=new node(data);
			return newnode;
		}
		node* insertnode(node* newnode,int data){
		if(newnode==NULL)
			return addnode(data);
		else if(data<newnode->data)
			newnode->left=insertnode(newnode->left,data);
		else if(data>newnode->data)
			newnode->right=insertnode(newnode->right,data);
		}
		void inorder(node *root){
			if(root==NULL)
				return;
			inorder(root->left);
			cout<<root->data<<"\t";
			inorder(root->right);
		}
};
int main(){
	BST tree;
	node *root=NULL;
	root=tree.insertnode(root,2);
	root=tree.insertnode(root,5);
	root=tree.insertnode(root,8);
	root=tree.insertnode(root,1);
	tree.inorder(root);
}













