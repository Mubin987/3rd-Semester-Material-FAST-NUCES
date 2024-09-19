#include <iostream>
using namespace std; 

class Queue{
public:
    int front;
    int rear;
    int arr[5];
    
    Queue(){
        front = -1;
        rear = -1;
        for(int i = 0; i<5; i++){
            arr[i] = 0;
        }
    }
    
    bool isEmpty(){
        if(rear == -1 && front == -1)
            return 1;
        else
            return 0;
    }
    
    void ADDMember(int val){
        if(QueueCapacity() == 1){
            return;
        }
        else if(isEmpty()){
            rear = 0;
            front = 0;
            arr[front] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    int QueueCapacity(){
		if(rear == sizeof(arr)/sizeof(int) - 1){
			cout << "\nQueue capacity is full"<<endl;
            return 1;}
        else
            return 0;
	}
    int RemoveMember(){
        int x;
        if(isEmpty()){
            cout << "Queue is empty!";
            return 0;
        }
        else if(front == rear){
        	cout<<"\nRemoved Member from front \n"<<endl;
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
            return x;
        }
        else{
        	cout<<"\nRemoved Member from front \n"<<endl;
            x = arr[front];
            for(int i = 0; i<4; i++){
            	arr[i]=arr[i+1];     
        	}
            arr[rear] = 0;
            rear--;
            return x;
        }
        
    }
    
    int count(){
        return rear-front+1;
    }
    
    void display(){
        for(int i = 0; i<5; i++){
            cout << arr[i] << "\t" ;     
        }
    }
};


int main(){
    Queue objq;
	objq.ADDMember(2);
	objq.ADDMember(4);
	objq.ADDMember(6);
	objq.ADDMember(8);
	objq.ADDMember(10);
	objq.ADDMember(12);
	objq.display();
	objq.RemoveMember();
	objq.display();
    

}




