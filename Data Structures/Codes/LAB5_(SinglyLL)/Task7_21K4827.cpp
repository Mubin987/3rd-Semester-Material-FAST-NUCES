#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
	Node(){
		data = 0;
		next = NULL;
	}
	
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList{
public:	
	Node* head;
	
	LinkedList(){
		head = NULL;
	}
	
	void insert(int data){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			return;
		}	
		
		else{
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = newNode;
		}
		
	
		
	}
	void append(Node *temp) { 
		Node *last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->next=NULL;
		return;
	}
	
	void push(Node *temp){
		
   		temp->next=head;
   		head=temp;
   		
	}
	void link(int data){
		Node* temp = head;
		Node* temp_prev = head;
		int count=0;
		while(temp->data != data){
			temp = temp->next;
			if(count>0)
				temp_prev = temp_prev->next;
			count++;
		}
		temp_prev->next=temp->next;
	}
	void printList(){
		
		Node* temp = head;
		
		if(head == NULL){
			cout << "List is empty!";
		}
		
		else{
			cout << "Elements of the list are:\n";
			while(temp != NULL){
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
	}
	void sort(){
		Node *loop=head;
		Node *temp;
		while(loop != NULL){
			
			if( loop->data % 2 != 0 && loop==head){
				
				temp=loop;
				loop = loop->next;
				head=temp->next;
				append(temp);
			}
			else{
				if(loop->data % 2 != 0){
					link(loop->data);
					append(loop);
				}
				loop = loop->next;		
			}
		}
		}	
	
};

int main(){
  	LinkedList list;
    list.insert(1);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(2);
    list.printList();
    list.sort();
    list.printList();
    
}


