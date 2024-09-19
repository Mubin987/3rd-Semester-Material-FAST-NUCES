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
		node *root=NULL;
		node* addnode(int data){
			node *newnode=new node(data);
			return newnode;
		}
		node* insertnode(node *roott,int data){
			if(roott==NULL){
				roott=addnode(data);
				return roott;
			}
			else if(roott->data>data){
				roott->left=insertnode(roott->left,data);
			}
			else if(roott->data<data){
				roott->right=insertnode(roott->right,data);
			}
		}
		void inorder(node *roott){
			if(roott==NULL)
				return;
			inorder(roott->left);
			cout<<roott->data<<"\t";
			inorder(roott->right);
		}
		void removal(node *roott,int k1,int k2){
			if(roott==NULL)
				return;
			if(roott->data>=k1&&roott->data<=k2){
				cout<<roott->data<<"\t";
			}
			removal(roott->left,k1,k2);
			removal(roott->right,k1,k2);
		}
};
int main(){
	BST tree;
	int arr[7]={ 15, 10, 20, 8, 12, 16, 25 };
	for(int i=0;i<7;i++){
	tree.root=tree.insertnode(tree.root,arr[i]);
	}
	cout<<"Inorder:"<<endl;
	tree.inorder(tree.root);
	int k1,k2;
	k1=9;k2=12;
	cout<<endl<<endl;
	cout<<"Inorder after removal:"<<endl;
	tree.removal(tree.root,k1,k2);
}


