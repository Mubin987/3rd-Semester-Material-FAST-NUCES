#include<iostream>
using namespace std;
class Node{
	int data;
	Node *next;
};
class stack{
	public:
		stack(){
			Node *head=NULL;
			Node *top=NULL;
		}
		bool insert(int data){
			Node *temp=new node(data);
			if(temp){
				;
				return 1;
			}
			if (!temp){
        		cout << "\nHeap Overflow";
        		exit(1);
    		}

			
		}
		bool pop(){
			if(top==-1){
				cout<<"\nStack is empty"<<endl;
				return 0;
			}
			else{
				cout<<"\nPopped index "<<top;
				array[top]=0;
				top--;
				return 1;
			}
		}
		void display(){
			cout<<endl<<endl;
			for(int i=top;i>=0;i--){
				cout<<array[i]<<endl;
			}
		}
		void recursive(int topp){
			if(topp==-1)
				return;
			cout<<array[topp]<<endl;
			recursive(topp-1)	;
		
		}
		
};

int main(){
	stack s;
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.insert(10);
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.insert(10);
	s.display();
	s.insert(12);
	
	cout<<endl<<endl;
	s.recursive(s.top);
}

