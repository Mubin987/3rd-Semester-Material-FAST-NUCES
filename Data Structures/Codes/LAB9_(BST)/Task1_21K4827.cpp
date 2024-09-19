#include<iostream>
using namespace std;
int ret=1;
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
		int check(node *root){
			
			if(root==NULL){
				return 0;
			}
			else if((root->left!=NULL&&root->data<root->left->data)||(root->right!=NULL&&root->data>root->right->data)){
				cout<<"\n0 Marks"<<endl;
				ret=0;
			}
			check(root->left);
			check(root->right);
			return ret;
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
	root=tree.addnode(5);
	node *l1=root->left=tree.addnode(1);
	node *r1=root->right=tree.addnode(10);
	r1->left=tree.addnode(6);
	tree.inorder(root);
	if(tree.check(root))
		cout<<"\n10 Marks"<<endl;
	cout<<endl;
	BST tree2;
	node *root2=NULL;
	root2=tree2.addnode(5);
	node *L1=root2->left=tree2.addnode(1);
	node *R1=root2->right=tree2.addnode(10);
	R1->left=tree.addnode(12);
	tree2.inorder(root2);
	if(tree2.check(root2))
		cout<<"\n10 Marks"<<endl;
	cout<<endl;
}
