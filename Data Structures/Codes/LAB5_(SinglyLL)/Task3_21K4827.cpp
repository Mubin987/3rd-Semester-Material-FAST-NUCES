#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
		}
		Node(int data){
			this->data=data;
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
			head=n;
		}
		void push(int data){
   		Node *newnode = new Node(data);
   		newnode->next=head;
   		head=newnode;
		}
		void displayList(){
   		Node *pnode = head;
   		while (pnode != NULL){
		    cout<<pnode->data<<"-->";
   			pnode = pnode->next;
   			if(pnode==NULL){
			   cout<<endl;
			}
		}
		}
};
int main(){
	SinglyLinkedList *list=new SinglyLinkedList();
	list->push(30);
	list->displayList();
	list->push(20);
	list->displayList();
	list->push(10);
	list->displayList();
}
