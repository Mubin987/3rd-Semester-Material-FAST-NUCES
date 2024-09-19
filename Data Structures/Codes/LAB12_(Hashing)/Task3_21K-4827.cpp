#include <bits/stdc++.h>
using namespace std;
class HashNode{
	public:
		int key,val;
		HashNode *next;
		HashNode(){
		}
		HashNode(int key,int val){
			this->val=val;
			this->key=key;
			next=NULL;
		}
};
class HashTable{
	private:
		HashNode **t;
	public:
		HashTable(){
			t=new HashNode*[10];
			for(int i=0;i<10;i++)
				t[i]=NULL;
		}
		int HashCalc(int v){
			int h=v%10;
			return h;
		}
		void insert(int v){
			int h=HashCalc(v);
			HashNode *temp=t[h];
			if(temp==NULL){
				t[h]=new HashNode(h,v);
				t[h]->next=temp;
			}
			else{
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=	new HashNode(h,v);
			}
		}
		void search(int v){
			int h=HashCalc(v);
			HashNode *temp=t[h];
			while(temp!=NULL){
					if(temp->val==v){
						cout<<temp->key<<endl;
						return;
					}
					temp=temp->next;
			}
			cout<<"Not found"<<endl;
		}
		void remove(int v){
			int h=HashCalc(v);
			if(t[h]->next==NULL)
				t[h]=NULL;
			else if(t[h]->val==v){
				t[h]=t[h]->next;	
			}
			else{
				HashNode *temp1=t[h];
				HashNode *temp2=t[h];
				while(temp1!=NULL){
					if(temp1->val==v){
						temp2->next=temp1->next;
						free(temp1);
						temp1==NULL;
						temp2==NULL;
						return;
					}
					temp2=temp1;
					temp1=temp1->next;
				}
			}
		}
		void display(){
			for(int i=0;i<10;i++){
				HashNode *temp=t[i];
				while(temp!=NULL){
					cout<<temp->val<<"->";
					temp=temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
};
int main(){
	HashTable t1;
	int n=5;
	int keys[n]={42,19,10,2,92};
	for(int i=0;i<n;i++){
		t1.insert(keys[i]);
	}
	t1.display();
	cout<<"\nFinding 92\n";
	cout<<"Key: ";
	t1.search(92);
	cout<<"\nDeleting 2"<<endl<<endl;
	t1.remove(2);
	t1.display();
}

