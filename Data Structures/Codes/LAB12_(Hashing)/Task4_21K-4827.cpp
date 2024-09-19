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
			t=new HashtableEntry[10];
			for(int i=0;i<n;i++){
				t[i].k=-1;
				t[i].v=0;
			}
		}
		int HashCalc1(int v){
			int h=v%13;
			return h;
		}
		int HashCalc2(int v){
			int h=7-v%7;
			return h;
		}
		void Insert(int val){
			int i=1;
			int h=(HashCalc1(val)+i*HashCalc2(val))%10;
			while(t[h].k!=-1){
				i++;
				h=(HashCalc1(val)+i*HashCalc2(val))%10;
				
			}
			t[h].k=h;
			t[h].v=val;
		}
		void searchKey(int val){
			int i=1;
			int hash=(HashCalc1(val)+i*HashCalc2(val))%10;
			int h;
			while(t[h].v!=val||h==hash){
				i++;
				h=(HashCalc1(val)+i*HashCalc2(val))%10;
				if(t[h].v==val){
				cout<<t[h].k<<endl;
				return;
			}
			
			}
			
			cout<<"Not Found"<<endl;
		}
		void remove(int val){
			int h=0,i=0;
			int hash=(HashCalc1(val)+i*HashCalc2(val))%10;
			while(t[h].v!=val&&i!=10){
				i++;
				h=i;
				if(t[h].v==val){
					t[h].v=0;
					t[h].k=-1;
					display();
					return;
			}
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
	int Keys[]={20,34,45,70,56};
	int n=sizeof(Keys)/sizeof(Keys[0]);
	HashMapTable t1(10);
	for(int i=0;i<n;i++){
		t1.Insert(Keys[i]);
	}
	t1.display();
	cout<<"Finding 20\n";
	cout<<"Key: ";
	t1.searchKey(20); 
	cout<<"\nDeleting 24 \n";
	t1.remove(24);
	cout<<"\nDeleting 56 \n";
	t1.remove(56);
}

