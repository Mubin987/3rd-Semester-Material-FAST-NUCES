#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *right,*left;
		node(){}
		node(int data){
			this->data=data;
			right=NULL;
			left=NULL;
		}
};
class BST{
	public:
		node *addnode(int data){
			node *newnode=new node(data);
			return newnode;
		}
		node *insert(node *roott,int data){
			if(roott==NULL){
				roott=addnode(data);
				return roott;
			}
			else if(data<roott->data){
				roott->left=insert(roott->left,data);
			}
			else if(data>roott->data){
				roott->right=insert(roott->right,data);
			}
		}
		void inorder(node *roott){
			if(roott==NULL)
				return;
			inorder(roott->left);
			cout<<roott->data<<" ";
			inorder(roott->right);
		}
		void postorder(node *roott){
			if(roott==NULL)
				return;
			postorder(roott->left);
			postorder(roott->right);
			cout<<roott->data<<" ";
		}
		void heapify(node* roott,int count){
			int largest=roott->data;
			int r=roott->right->data;
			int l=roott->left->data;
			if(r>largest&&count<2){
				largest=r;
			}
			if(l>largest&&count<2){
				largest=l;
			}
			if(largest!=roott->data&&largest==r){
				roott->right->data=roott->data;
				roott->data=r;
				heapify(roott->right,count++);
			}
			else if(largest!=roott->data&&largest==l){
				roott->left->data=roott->data;
				roott->data=l;
				heapify(roott->left,count++);
			}
}

void insertheap(node *roott){
	heapify(roott->right,0);
	heapify(roott->left,0);
	heapify(roott,0);
}		
};

int main(){
	node *root=NULL;
	BST tree;
	root=tree.insert(root,4);
	root=tree.insert(root,1);
	root=tree.insert(root,2);
	root=tree.insert(root,3);
	root=tree.insert(root,5);
	root=tree.insert(root,6);
	root=tree.insert(root,7);
	tree.inorder(root);
	cout<<endl<<endl;
	cout<<endl<<endl;
	tree.insertheap(root);
}
