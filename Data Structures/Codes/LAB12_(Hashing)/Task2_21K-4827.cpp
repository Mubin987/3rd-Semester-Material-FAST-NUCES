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
				t[i].k=-1;
				t[i].v=0;
			}
		}
		int HashCalc(int v){
			int h=v%10;
			return h;
		}
		void Insert(int val){
			int h=HashCalc(val);
			while(t[h].k!=-1){
				h=HashCalc(h+1);
			}
			t[h].k=h;
			t[h].v=val;
		}
		void searchKey(int val){
			int hash=HashCalc(val);
			int h=hash;
			while(t[h].k!=-1&&HashCalc(t[h].v)==hash){
				if(t[h].k!=-2&&t[h].v==val){
					cout<<t[h].k<<endl;
					return;
				}
				h=HashCalc(h+1);
			}
			cout<<"Not found"<<endl;		
		}
		void remove(int val){
			int hash=HashCalc(val);
			//-2 for deleted
			int h=hash;
			while(t[h].k!=-1&&hash==HashCalc(t[h].v)){
				if(t[h].v==val&&t[h].k!=-2){
				t[h].k=-2;
				return;
			}
			h=HashCalc(h+1);
			}
			cout<<"Not Found"<<endl;
		}
		void display(){
			cout<<endl;
			for(int i=0;i<10;i++){
				cout<<t[i].v<<"\t";
			}
			cout<<endl<<endl;
			for(int i=0;i<10;i++){
				cout<<t[i].k<<"\t";
			}
			cout<<endl<<endl;
		}
};

int main(){
	int n=7;
	int Keys[n]={24,54,91,67,48,89,64};
	HashMapTable t1(10);
	for(int i=0;i<n;i++){
		t1.Insert(Keys[i]);
	}
	t1.display();
	cout<<"Finding 24\n";
	cout<<"Key: ";
	t1.searchKey(24); 
	cout<<"\nDeleting 54 \n";
	t1.remove(54);
	t1.display();
	cout<<"Finding 24\n";
	cout<<"Key: ";t1.searchKey(24);
	cout<<"\nFinding 54\n";
	cout<<"Key: ";
	t1.searchKey(54);
}

