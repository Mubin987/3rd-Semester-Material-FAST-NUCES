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
		void append(int new_data) { 
        Node *newNode = new Node(new_data); 
		if (head == NULL) { 
			head = newNode;
			return; 
        }
		Node *last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = newNode;
		return;
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
	list->append(10);
	list->displayList();
	list->append(20);
	list->displayList();
	list->append(30);
	list->displayList();
}
