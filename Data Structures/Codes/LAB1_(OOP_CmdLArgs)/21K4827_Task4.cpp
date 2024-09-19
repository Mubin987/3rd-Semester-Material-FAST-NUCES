#include<iostream>
using namespace std;
int factors (int); 
int main () {
	int num;
	do{
		cout<<"Enter number: ";
		cin>>num;
		if(num<-1){
			cout<<"Enter number greater than 0\n";
			continue;
		}
	int sum=factors(num);
	cout<<"\nSum: "<<sum<<endl;
	}while(num!=-1);
}
int factors (int num) {
	
		int sum=0;
		cout << "Factors of " << num << " are: ";  
    	for(int i = 1; i <= num; ++i) {
        	if(num % i == 0){
        		sum+=i;
            	cout << i << " ";
            }
    	}
    	return sum;
}
