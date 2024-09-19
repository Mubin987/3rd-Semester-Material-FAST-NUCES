#include <iostream>
using namespace std; 
class Node{
	public:
	int data;
	Node *next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
class Queue{
	public:
		Queue(){
		}
		Node *front=NULL;
		Node *rear=NULL;
		bool ADDMember(int data){
			Node *newnode=new Node(data);
			if(newnode){
				if(front==NULL)
					front=newnode;
				else{
				rear->next=newnode;}	
				rear=newnode;
				return 1;
			}
			QueueCapacity(newnode);
    	}
    	
		void QueueCapacity(Node *newnode){
			if (!newnode){
        		cout << "\nHeap Overflow (Queue capacity is full)";
        		exit(1);
			}	
		}
		
		bool RemoveMember(){
			if(rear==NULL){
				cout<<"\nQueue is empty"<<endl;
				return 0;
			}
			else{
				front=front->next;
				cout<<"\nRemoved Member from front \n"<<endl;
				return 1;
			}
		}
		void display_Queue(){
			Node *temp=front;
				while(temp!=NULL){
					cout<<temp->data;
					temp=temp->next;
					cout<<"->";
				}
		}
		
};

int main(){
    Queue objq;
	objq.RemoveMember();
	objq.ADDMember(2);
	objq.ADDMember(4);
	objq.ADDMember(6);
	objq.ADDMember(8);
	cout<<endl<<endl;
	objq.display_Queue();
	objq.RemoveMember();
	objq.display_Queue();
    
    
    
}




