#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		int key;
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
		void insertAfterNode(Node *prev_node,int data){
		if(prev_node==NULL){
			cout<<"Cannot perform action..."<<endl;
		}
		else{
   		Node *newnode = new Node(data);
   		newnode->next=prev_node->next;
   		prev_node->next=newnode;
		}
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
	list->append(20);
	list->append(30);
	list->displayList();
	list->insertAfterNode(list->head,15);
	list->displayList();
}
