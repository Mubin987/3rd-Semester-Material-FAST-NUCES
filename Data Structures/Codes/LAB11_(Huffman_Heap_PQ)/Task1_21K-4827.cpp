#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node{
   int freq;
   char data;
   const node *left, *right;
   node(char d, int f = -1){
      data = d;
      freq = f;
      left = NULL;
      right = NULL;
   }
   node(const node *l, const node *r){
      data = 0;
      freq = l->freq + r->freq;
      left=l;
      right=r;
   }
   bool operator<( const node &a ) const { 
      return freq >a.freq;
   }
   void traverse(string code = "")const{
      if(left!=NULL){
         left->traverse(code+'0'); 
         right->traverse(code+'1');
      }else{
         cout << "Data: " << data<< ", Freqency: "<<freq << ", Code: " << code<<endl;
      }
   }
};
void huffmanCoding(string str){
   priority_queue<node> q;
   int freqency[256];
   for(int i = 0; i<256; i++)
      freqency[i] = 0; 
   for(int i = 0; i<str.size(); i++){
      freqency[int(str[i])]++; 
   }
   for(int i = 0; i<256; i++){
      if(freqency[i]){
         q.push(node(i, freqency[i]));
      }
   }
   while(q.size() >1){
      node *l = new node(q.top());
      q.pop();
      node *r = new node(q.top()); 
      q.pop();
      q.push(node(l, r));
   }
   cout << "Huffman Code: "<<endl;
   q.top().traverse(); 
}
main(){
   string str = "Class BCS-3D";
   huffmanCoding(str);
}
