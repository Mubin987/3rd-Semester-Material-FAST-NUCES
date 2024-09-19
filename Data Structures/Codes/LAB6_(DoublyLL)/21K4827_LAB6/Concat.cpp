#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
};
class LinkedList{
	public:
		Node *head=NULL;
		LinkedList(){}
		LinkedList(LinkedList a,LinkedList b){
			Node *temp=a.head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=b.head;
			b.head->prev=temp;
			head=a.head;
		}
	void push(int data){
		Node *newnode=new Node(data);
		newnode->next=head;
		if(head!=NULL){
			head->prev=newnode;
		}
		head=newnode;
	}
	void append(int data){
		
		if(head==NULL){
			push(data);
		}
		
		else{
			Node *newnode=new Node(data);
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
	void print(){
		Node *temp=head;
		while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
	}
};
int main(){
	LinkedList l1;
	l1.append(1);
	l1.append(2);
	l1.append(3);
	l1.print();
	cout<<endl;
	LinkedList l2;
	l2.append(4);
	l2.append(5);
	l2.append(6);
	l2.print();
	cout<<endl;
	LinkedList l3(l1,l2);
	l3.print();
}









