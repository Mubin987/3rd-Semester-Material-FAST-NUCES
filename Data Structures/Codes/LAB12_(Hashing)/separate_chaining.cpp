#include<iostream>
#include<list>
using namespace std;
#define n 10
class studentnode{
	public:
		string name;
		int rolln,k;
		studentnode *next;
		studentnode(){}
		studentnode(int k,int rolln,string name){
			this->rolln=rolln;
			this->k=k;
			this->name=name;
			next=NULL;
		}
};
class hashtable{
	studentnode **t;
	public:
		hashtable(){
			t=new studentnode*[n];
			for(int i=0;i<n;i++){
				t[i]=NULL;
			}
		}
		int hashcalc(int rolln){
			return rolln%n;
		}
		void insert(int rolln,string name){
			int h=hashcalc(rolln);
			studentnode *temp=t[h];
			studentnode *newnode=new studentnode(h,rolln,name);
			t[h]=newnode;
			newnode->next=temp;
		}
		void search(int rolln){
			int h=hashcalc(rolln);
			studentnode *temp=t[h];
			while(temp!=NULL){
				if(temp->rolln==rolln){
					cout<<"Key: "<<temp->k<<endl<<endl;
					return;
				}
				temp=temp->next;
			}
			cout<<"Not found"<<endl;
		}
		void remove(int rolln){
			int h=hashcalc(rolln);
			if(t[h]->rolln==rolln){
				t[h]=t[h]->next;
				return;
			}
			studentnode *temp1=t[h];
			studentnode *temp2=t[h];
			while(temp1!=NULL){
				if(temp1->rolln==rolln){
					temp2->next=temp1->next;
					free(temp1);
					temp1=NULL;
					temp2=NULL;
					return;
				}
				temp2=temp1;
				temp1=temp1->next;
			}
			cout<<"Not found"<<endl;
		}
		void display(){
			for(int i=0;i<n;i++){
				studentnode *temp=t[i];
				while(temp!=NULL){
					cout<<temp->rolln<<"_"<<temp->name<<"->";
					temp=temp->next;
				}
				cout<<"NULL"<<endl<<endl;
			}
		}
};
int main(){
	list<pair<int,string>> l;
	l.push_back(make_pair(4827,"Mubin"));
	l.push_back(make_pair(3432,"Aalyan"));
	l.push_back(make_pair(4516,"Ahmed"));
	l.push_back(make_pair(4588,"Hamza"));
	l.push_back(make_pair(4246,"Random"));
	hashtable t1;
	for(auto x:l){
		t1.insert(x.first,x.second);
	}
	t1.display();
	cout<<"Searching 4246\n"<<endl;
	t1.search(4246);
	cout<<"Removing 4246\n"<<endl;
	t1.remove(4246);
	cout<<"Searching 4246\n"<<endl;
	t1.search(4246);
	cout<<endl;
	t1.display();
}

