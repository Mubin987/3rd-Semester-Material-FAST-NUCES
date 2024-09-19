#include <iostream>
#include <string>
using namespace std;
class HashtableEntry{
	public:
	int k,v;
	HashtableEntry(){
	}
	HashtableEntry(int k,int v){
		this->k=k;
		this->v=v;
	}
};
class HashMapTable{
	private:
		HashtableEntry *t;
	public:
		HashMapTable(int n) {
			t=new HashtableEntry[n];
			for(int i=0;i<10;i++){
				t[i].k=0;
				t[i].v=0;
			}
		}
		int HashCalc(int v){
			int h=v%10;
			return h;
		}
		void Insert(int val){
			int h=HashCalc(val);
			t[h].k=h;
			t[h].v=val;
		}
		void searchKey(int val){
			int h=HashCalc(val);
			if(t[h].v==val){
				cout<<t[h].k<<endl;
				return;
			}
			cout<<"Not Found"<<endl;
		}
		void remove(int val){
			int h=HashCalc(val);
			t[h].k=0;
			t[h].v=0;
		}
		void display(){
			for(int i=0;i<10;i++){
				cout<<t[i].v<<" ";
			}
		}
};

int main(){
	int n=6;
	int Keys[n]={24,52,91,67,48,89};
	HashMapTable t1(10);
	for(int i=0;i<n;i++){
		t1.Insert(Keys[i]);
	}
	t1.display();
	cout<<endl;
	cout<<"Finding 24\n";
	cout<<"Key: ";
	t1.searchKey(24);
	cout<<"\nDeleting 24 \n";
	t1.remove(24);
	t1.display();
	cout<<"\nFinding 24\n";
	cout<<"Key: ";t1.searchKey(24);
}

