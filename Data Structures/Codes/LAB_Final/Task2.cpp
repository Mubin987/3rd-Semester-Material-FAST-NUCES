#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(){}
		node(int data){
			this->data=data;
			next=NULL;
		}
};
class linkedlist{
	public:
		node* head=NULL;
		node* n=NULL;
		void insert(int data){
			node* newnode=new node(data);
			if(head==NULL){
				head=newnode;
				n=head;
			}
			else{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				n=newnode;
				temp->next=newnode;
			}	
		}
		void print(){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
		}
		void reorder(){
			node* temp=head;
			node* temp2=temp->next;
			temp->next=n;
			n->next=temp2;
			temp2->next->next=NULL;
		}
};
int main(){
	linkedlist l1;
	l1.insert(1);
	l1.insert(3);
	l1.insert(5);
	l1.insert(7);
	l1.print();
	l1.reorder();
	cout<<endl;
	l1.print();
}
