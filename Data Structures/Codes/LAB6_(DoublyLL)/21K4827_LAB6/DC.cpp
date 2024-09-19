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
	void push(int data){
		Node *newnode=new Node(data);
		
		if(head==NULL){
			newnode->next = newnode;
			newnode->prev = newnode;
			head=newnode;
		}
		else{
			Node *temp = head;
		newnode->next=head;
		head->prev = newnode;
		while(temp->next!=head){
				temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev = temp;
		head=newnode;
	}}
	void append(int data){
		
		if(head==NULL){
			push(data);
		}
		
		else{
			Node *newnode=new Node(data);
			Node *temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=head;
			head->prev=newnode;
		}
	}
	void insert(int position,int data){
		int counter=1;
		Node *temp=head;
		while(temp->next != head){
			temp=temp->next;
			counter++;
		}
		if(position==0){
			push(data);
		}
		else if(position-counter==0){
			append(data);
		}
		else{
		Node* temp = head;
		Node* temp_prev = head;
		int counter=0;
		Node *newnode=new Node(data);
		while(counter != position){
			temp=temp->next;
			if(counter>0){
				temp_prev=temp_prev->next;
			}
			counter++;
		}
		temp_prev->next=newnode;
		newnode->prev=temp_prev;
		temp->prev=newnode;
		newnode->next=temp;
	}
	}
	void deletenode(int position){
		Node* temp = head;
		Node* temp_prev = head;
		int counter=0;
		while(counter != position){
			temp=temp->next;
			if(counter>0){
				temp_prev=temp_prev->next;
			}
			counter++;
		}
		temp_prev->next=temp->next;
		temp->next->prev=temp_prev;
		delete temp;
		temp=NULL;
	}
	void print(){
		Node *temp=head;
		do{
				cout<<temp->data<<endl;
				temp=temp->next;
			}while(temp!=head);
	}
};
int main(){
	LinkedList l1;
	l1.push(2);
	l1.push(1);
	l1.append(3);
	l1.append(5);
	l1.push(0);
	l1.insert(4,4);
	l1.deletenode(5);
	l1.print();
	
}









