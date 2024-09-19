#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};
class tree{
	public:
	node* addnode(int data){
		node* newnode= new node(data);
		return newnode;
	}
	node* insertnode(node* rootnode,int data){
		if(rootnode==NULL){
			rootnode=addnode(data);
			return rootnode;
		}
		else if(rootnode->data<data){
			rootnode->right=insertnode(rootnode->right,data);
		}
		else if(rootnode->data>data){
			rootnode->left=insertnode(rootnode->left,data);
		}
	}
	void inorder(node* root){
		if(root==NULL)
			return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
};
int main(){
	tree bst;
	node* root=NULL;
	root=bst.insertnode(root,5);
	root=bst.insertnode(root,7);
	root=bst.insertnode(root,2);
	root=bst.insertnode(root,4);
	bst.inorder(root);
}













