#include<iostream>
using namespace std;
int main () {
	int num,sum;
	do{
		cout<<"Enter number: ";
		cin>>num;
		if(num<-1){
			cout<<"Enter number greater than 0\n";
			continue;
		}
		sum=0;
		cout << "Factors of " << num << " are: ";  
    	for(int i = 1; i <= num; ++i) {
        	if(num % i == 0){
        		sum+=i;
            	cout << i << " ";
            }
    	}
    	cout<<"\nSum: "<<sum<<endl;
	}while(num!=-1);
	return 0;
}