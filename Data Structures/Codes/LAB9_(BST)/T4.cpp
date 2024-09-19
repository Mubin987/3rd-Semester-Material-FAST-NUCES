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
		node* minNodeRemoval(node* roott){
			if(roott->left->left==NULL)
				return roott->left;
			else{
				node* minParent=minNodeRemoval(roott->left);
				node* min=minParent->left;
				minParent->left=min->right;
			cout<<min->data<<endl;
			return min;}
		}
		node* remove2childnode(node* roott){
			if(roott->right->left==NULL){
				node* X=roott->right;
				roott->right=X->right;
				roott->data=X->data;
				X->data=0;
				return roott;
			}
			else if(roott->right->left->left==NULL && roott->right->left!=NULL && roott->right->left->right!=NULL){
				node* X=roott->right->left;
				roott->data=X->data;
				roott->right->left=X->right;
				X->data=0;		
				return roott;
			}
			else{
				node* Y=roott->right;
				node* X=minNodeRemoval(Y);
				roott->data=X->data;
				X->data=0;		
				return roott;
			}

		}
		node* remove1childnode(node* roott){
			if(roott->left!=NULL){
				roott->data=roott->left->data;
				return roott;}
			if(roott->right!=NULL){
				roott->data=roott->right->data;
				return roott;}
		}
		
		void removal(node *roott,int k1,int k2){
			if(roott==NULL)
				return;
			removal(roott->left,k1,k2);
			if(roott->data<k1||roott->data>k2){
				if(roott->left!=NULL&&roott->right!=NULL){
					roott=remove2childnode(roott);
				}
				
				else if(roott->left==NULL&&roott->right==NULL){
					roott->data=0;
				}	
				else if(roott->left!=NULL||roott->right!=NULL){
					roott=remove1childnode(roott);
				}
					
			}
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
	tree.removal(tree.root,k1,k2);
	tree.removal(tree.root,k1,k2);
	cout<<endl<<endl;
	cout<<"Inorder after removal:"<<endl;
	tree.inorder(tree.root);
}


