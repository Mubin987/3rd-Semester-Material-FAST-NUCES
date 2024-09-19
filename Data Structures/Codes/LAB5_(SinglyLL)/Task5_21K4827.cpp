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
	void deletenode(int data){
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
		delete temp;
		temp=NULL;
	}
	void deletelastnode(){
	Node* temp = head;
		Node* temp_prev = head;
		int count=0;
		while(temp->next != NULL){
			temp = temp->next;
			if(count>0)
				temp_prev = temp_prev->next;
			count++;
		}
		temp_prev->next=NULL;
		delete temp;
		temp=NULL;
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
    list.deletenode(5);
    list.printList();
    list.deletelastnode();
    list.printList();
}


