#include<iostream>
#include<vector>
using namespace std;
class graph{
	vector<int> *v1;
	public:
		graph(int v){
			v1=new vector<int>[v];
		}
		void addedge_undirected(int s,int d){
			v1[s].push_back(d);
			v1[d].push_back(s);
		}
		void addedge_directed(int s,int d){
			v1[s].push_back(d);
		}
		void print(int V){
			for(int i=0;i<V;i++){
//				for(int j=0;j<v1[i].size();j++)
//					cout<<v1[i][j]<<"  ";
				for(auto x:v1[i])
					cout<<x<<"  ";
			cout<<endl<<endl;
			}
		}
		void remove(int r){
			for(int i=0;i<4;i++){
				for(int j=0;j<v1[i].size();j++){
					if(v1[i][j]==r){
						swap(v1[i][j],v1[i][v1[i].size()-1]);
						v1[i].pop_back();
					}
//				for(auto x:v1[i])
//					cout<<x<<"  ";
			}
			}
			 v1[r].clear();
		}
};
int main(){
	
	graph G2(4);
	cout<<"Directed Graph\n";
	G2.addedge_directed(1,3);
	G2.addedge_directed(0,2);
	G2.addedge_directed(1,2);
	G2.addedge_directed(2,3);
	G2.addedge_directed(3,0);
	G2.print(4);
	cout<<"Directed Graph after vertix 1 deletion\n";
	G2.remove(1);
	G2.print(4);
	graph G1(4);
	cout<<"\nUndirected Graph\n\n";
	G1.addedge_undirected(1,3);
	G1.addedge_undirected(0,2);
	G1.addedge_undirected(1,2);
	G1.addedge_undirected(2,3);
	G1.print(4);
}






