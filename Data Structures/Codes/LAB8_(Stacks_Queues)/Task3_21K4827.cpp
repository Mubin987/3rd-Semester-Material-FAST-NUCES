#include<iostream>
using namespace std;
class stack{
	public:
		int top;
		stack(){
			top=-1;
		}
		char arr[20]={0};
		bool insert(char data){
			if(top<19){
				top++;
				arr[top]=data;
				return 1;
			}
			
				cout<<"\nStack Overflow"<<endl;
				return 0;
			
		}
		void pop(){
			if(top==-1){
				cout<<"\nStack is empty"<<endl;
			}
			else{
				cout<<"\nPopped index "<<top;
				arr[top]=0;
				top--;
			}
		}
		void display(){
			cout<<endl<<endl;
			for(int i=0;i<20;i++){
				cout<<arr[i]<<endl;
			}
		}
		int empty(){
			if(top==-1)
				return 1;
			else
				return 0;	
		}
};
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s_)
{
  
    stack s;
    string result;
  
    for (int i = 0; i < s_.length(); i++) {
        char c = s_[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            s.insert('(');
  
        else if (c == ')') {
            while (s.arr[s.top] != '(') {
                result += s.arr[s.top];
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty()&& prec(s_[i]) <= prec(s.arr[s.top])){
                result += s.arr[s.top];
                s.pop();
            }
            s.insert(c);
        }
    }
    while (!s.empty()) {
        result += s.arr[s.top];
        s.pop();
    }
  
    cout <<endl<<endl<< result << endl;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)";
    infixToPostfix(exp);
    return 0;
}
