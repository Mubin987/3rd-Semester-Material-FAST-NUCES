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
	void Palindrome(){
		Node *temp=head;
		int count=0;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
		int *arr=new int[count];
		temp=head;
		count=0;
		while(temp != NULL){
			arr[count]=temp->data;
			count++;
			temp = temp->next;
		}
		for(int i=0;i<count;i++){
			if(arr[i]!=arr[count-i-1]){
				cout<<"Not a palindrome"<<endl;
				return;
			}
		}
		cout<<"Palindrome"<<endl;
	}
};

int main(){
  	LinkedList list;
    list.insert('a');
    list.insert('b');
    list.insert('c');
    list.insert('b');
    list.insert('a');
    list.printList();
    list.Palindrome();
    LinkedList list2;
    list2.insert(1);
    list2.insert(4);
    list2.insert(5);
    list2.insert(4);
    list2.insert(1);
    list2.printList();
    list2.Palindrome();
    LinkedList list3;
    list3.insert(1);
    list3.insert(2);
    list3.insert(3);
    list3.insert(4);
    list3.insert(5);
    list3.printList();
    list3.Palindrome();
}


