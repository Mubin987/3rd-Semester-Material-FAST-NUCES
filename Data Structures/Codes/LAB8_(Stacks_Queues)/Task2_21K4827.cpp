#include<iostream>
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
class stack{
	public:
		stack(){
		}
		Node *head=NULL;
		Node *top=NULL;
		bool insert(int data){
			Node *newnode=new Node(data);
			if(newnode){
				if(head==NULL)
					head=newnode;
				else{
				top->next=newnode;}	
				top=newnode;
				return 1;
			}
			if (!newnode){
        		cout << "\nHeap Overflow";
        		exit(1);
    		}

			
		}
		bool pop(){
			if(top==NULL){
				cout<<"\nStack is empty\n"<<endl;
				return 0;
			}
			else{
				Node *temp=head;
				cout<<"\nPopped top \n"<<endl;
				while(temp->next!=top){
					temp=temp->next;
				}
				top=temp;
				top->next=NULL;
				return 1;
			}
		}
		void display_stack_backwards(){
			Node *temp=head;
				while(temp!=NULL){
					cout<<temp->data<<endl;
					temp=temp->next;
				}
		}
		void display_stack(Node *temp){
			if(temp==NULL)
				return;
			display_stack(temp->next);
			cout<<temp->data<<endl;
		
		}
		
};

int main(){
	stack s;
	s.pop();
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.display_stack_backwards();
	cout<<endl<<endl;
	s.display_stack(s.head);
	s.pop();
	s.display_stack(s.head);
}

