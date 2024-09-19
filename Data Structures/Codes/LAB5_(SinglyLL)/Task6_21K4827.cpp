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
	int updatenode(int data,int update){
		Node* temp = head;
		while(temp->next != NULL){
			if(temp->data == data){
				temp->data = update;
				return 0;
			}
			temp = temp->next;
		}
		cout<<"Node does not exist."<<endl;
		return 0;
	}
};

int main(){
  	LinkedList list;
    list.insert(4);
    list.insert(1);
    list.insert(5);
    list.insert(7);
    list.insert(2);
    list.printList();
    list.updatenode(7,6);
    list.printList();
}


