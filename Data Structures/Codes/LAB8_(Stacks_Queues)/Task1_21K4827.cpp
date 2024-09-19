#include<iostream>
using namespace std;
class stack{
	int top;
	public:
		stack(){
			top=-1;
		}
		int array[10]={0};
		bool insert(int data){
			if(top<9){
				top++;
				array[top]=data;
				return 1;
			}
			
				cout<<"\nStack Overflow"<<endl;
				return 0;
			
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
			for(int i=0;i<10;i++){
				cout<<array[i]<<endl;
			}
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
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.display();
}
