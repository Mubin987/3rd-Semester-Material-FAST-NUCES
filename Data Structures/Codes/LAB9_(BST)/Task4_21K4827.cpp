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
		node* FindMin(node* root){
			while(root->left != NULL) root = root->left;
			return root;
		}

	node* Delete(node *roott, int data) {
		if(roott == NULL) return roott;
		else if(data < roott->data) 
			roott->left = Delete(roott->left,data);
		else if (data > roott->data) 
			roott->right = Delete(roott->right,data);	
		else {
			if(roott->left == NULL && roott->right == NULL) { 
				free(roott);
				roott = NULL;
			}
			else if(root->left == NULL) {
				node *temp = roott;
				roott = roott->right;
				free(temp);
				delete temp;
			}
			else if(root->right == NULL) {
				node *temp = roott;
				roott = roott->left;
				free(temp);
				delete temp;
			}
			else { 
				node *temp = FindMin(roott->right);
				roott->data = temp->data;
				roott->right = Delete(roott->right,temp->data);
			}
		}
	return roott;
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
	for(int i=0;i<7;i++){
		if(arr[i]<k1||arr[i]>k2)
			tree.root=tree.Delete(tree.root,arr[i]);
	}
	
	cout<<endl<<endl;
	cout<<"Inorder after removal:"<<endl;
	tree.inorder(tree.root);
}


