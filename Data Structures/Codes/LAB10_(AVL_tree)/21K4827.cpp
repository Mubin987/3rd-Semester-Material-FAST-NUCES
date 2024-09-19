#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
		node(int data){
			this->data=data;
			this->right=NULL;
			this->left=NULL;
		}
};
class AVL{
	public:
		node* addnode(int data){
			node *newnode= new node(data);
			return newnode;
		}
		int heightBST(node *root){
			int h=-1;
			if(root!=NULL){
				int lst=heightBST(root->left);
				int rst=heightBST(root->right);
				int maxm=max(lst,rst);
				h=maxm+1;
			}
			return h;
		}
		int BalanceFactor(node* root){
			if(root==NULL)
				return 0;
			else{
				int bf=heightBST(root->left)-heightBST(root->right);
				return bf;
			}
		}
		node* RotateRight(node* root){
			node* X=root->left;
			node* temp=X->right;
			
			X->right=root;
			root->left=temp;
			return X;
		}
		node* RotateLeft(node* root){
			node* X=root->right;
			node* temp=X->left;
			
			X->left=root;
			root->right=temp;
			return X;
		}
		node* insert(node *root,int data){
			if(root==NULL)
				return addnode(data);
			else if(data>root->data)
				root->right = insert(root->right,data);
			else if(data<root->data)
				root->left = insert(root->left,data);
			int bf=BalanceFactor(root);
			if(bf>1&&data<root->left->data)
				return RotateRight(root);
			else if(bf<-1&&data>root->right->data)
				return RotateLeft(root);
			else if(bf>1&&data>root->left->data){
				root->left = RotateLeft(root->left);
				return RotateRight(root);
			}
			
			else if(bf<-1&&data<root->right->data){
				root->right = RotateRight(root->right);
				return RotateLeft(root);
			}
			return root;	
		}
		void preorder(node* root){
			if(root==NULL)
				return;
			cout<<root->data<<"\t";		
			preorder(root->left);
		
			preorder(root->right);
		}
		void inorder(node* root){
			if(root==NULL)
				return;
			inorder(root->left);
			cout<<root->data<<"\t";
			inorder(root->right);
		}
		void postorder(node* root){
			if(root==NULL)
				return;
			postorder(root->left);
			postorder(root->right);
			cout<<root->data<<"\t";	
		}
		node* FindMin(node* root){
			while(root->left!=NULL)
				root=root->left;
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
				delete roott;
				roott = NULL;
			}
			else if(roott->left == NULL) {
				node *temp = roott;
				roott = roott->right;
				delete temp;
			}
			else if(roott->right == NULL) {
				node *temp = roott;
				roott = roott->left;
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
	node* root=NULL;
	AVL tree;
	root=tree.insert(root,1);
	root=tree.insert(root,2);
	root=tree.insert(root,3);
	cout<<"Root:"<<root->data<<endl;
	tree.preorder(root);
	cout<<endl;
	tree.inorder(root);
	cout<<endl;
	tree.postorder(root);
	root=tree.Delete(root,2);
	cout<<"\n\nAfter deletion of root node 2"<<endl;
	cout<<"Root:"<<root->data<<endl;
	tree.preorder(root);
	cout<<endl;
	tree.inorder(root);
	cout<<endl;
	tree.postorder(root);
	cout<<"\n\nAfter insertion of 4,5,6,7,8"<<endl;
	root=tree.insert(root,4);
	root=tree.insert(root,5);
	root=tree.insert(root,6);
	root=tree.insert(root,7);
	root=tree.insert(root,8);
	cout<<endl;
	tree.preorder(root);
	cout<<endl;
	tree.inorder(root);
	cout<<endl;
	tree.postorder(root);
	cout<<"\n\nAfter deletion of 5,8"<<endl;
	root=tree.Delete(root,8);
	root=tree.Delete(root,5);
	cout<<endl;
	tree.preorder(root);
	cout<<endl;
	tree.inorder(root);
	cout<<endl;
	tree.postorder(root);
}
