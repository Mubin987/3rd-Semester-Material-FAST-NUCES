#include<iostream>
using namespace std;
void adjustentry(int type ,char entry){
	//open file
	if(entry=='r'&&type==1){
		//unearned revenue & service revenue adjustment 
	}
	else if(entry=='r'&&type==2){
		//accounts receivable & service revenue adjustment
	}
	else if(entry=='x'&&type==1){
		//prepaid & expense adjustment
	}
	else if(entry=='x'&&type==2){
		//payable & expense adjustment
	}
	//print adjusted trial balance
	//close file
}

int main()
{
    cout << "How many enteries you want to adjust? ";
    int  num;char entry;
    cin >> num;
    int type;

    for (int i = 0; i < num; i++)
    {
        cout << "Entry No: " << i+1 << endl;
        cout << "Is it deffered or accrued? \n"
             << "1. Deffered. \n2. Accrued."<<endl;
        do{
            cin>>type;
		}while(type!=1&&type!=2);
        switch (type)
        {
        case 1:
            cout<<"Press 'r' for revenue and 'x' for expense entry: ";
            do{
            	cin>>entry;
			}while(entry!='r'&&entry!='x');
            adjustentry(type,entry);
        break;
        case 2:
            cout<<"Press 'r' for revenue and 'x' for expense entry: ";
            do{
            	cin>>entry;
			}while(entry!='r'&&entry!='x');
            adjustentry(type,entry);
        break;
        default:
        break;
        }
    }
}

