#include<iostream>
#include<queue>

using namespace std;
 
int DecreasingArray(int arr[], int n)
{
    int sum = 0;
	int Difference = 0;
    priority_queue<int, vector<int>, greater<int> > p_Queue;
    for (int i = 0; i < n; i++) {
        if (!p_Queue.empty() && p_Queue.top() < arr[i]) {
            Difference = arr[i] - p_Queue.top();
            sum =sum+Difference;
            p_Queue.pop();
            p_Queue.push(arr[i]);
        }
        p_Queue.push(arr[i]);
    }
 
    return sum;
}
int main()
{
	int N ;
    cout<<"Array length: ";
    cin>>N;
    int arr[N],val;
    cout<<"Array values: ";
    for(int i=0;i<N;i++){
    	cin>>val;
		arr[i]=val;
	}
    cout <<"Steps required: "<< DecreasingArray(arr, N);
 
    return 0;
}
