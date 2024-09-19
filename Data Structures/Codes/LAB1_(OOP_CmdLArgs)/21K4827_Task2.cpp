#include<iostream>
#include<fstream>
using namespace std;
int main (int argc,char** argv) {
	ofstream file;
	file.open (argv[1]);
	file << "Coding is fun.\n";
	file.close();
	ifstream file1;
	string a,b,c;
	file1.open (argv[1]);
	file1>>a>>b>>c;
	cout<<a<<" "<<b<<" "<<c<<" ";
	file1.close();
	ofstream file2;
	file2.open (argv[2]);
	file2 <<a<<" "<<b<<" "<<c<<" ";
	file2.close();
	return 0;
}