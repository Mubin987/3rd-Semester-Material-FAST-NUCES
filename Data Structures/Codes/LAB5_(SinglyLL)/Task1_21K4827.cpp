#include<iostream>
using namespace std;

class Node{
	public:
		int data;
//		int key;
		Node *next;
		Node(){
		}
		Node(int data/*,int key*/){
			this->data=data;
//			this->key=key;
			next=NULL;
		}
};
class SinglyLinkedList{
	public:
		Node *head;
		SinglyLinkedList(){
			head=NULL;
		}
		SinglyLinkedList (Node *n){
			n=head;
		}
};
int main(){
	
}
