#include <iostream>
using namespace std;

void Heapifymax(int arr[], int s, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
   
    if(l < s && arr[l] > arr[largest])
        largest = l;
       
    if(r < s && arr[r] > arr[largest])
        largest = r;
       
    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapifymax(arr, s, largest);
    }
}

void Heapifymin(int arr[], int s, int i){
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
   
    if(l < s && arr[l] < arr[smallest])
        smallest = l;
       
    if(r < s && arr[r] < arr[smallest])
        smallest = r;
       
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        Heapifymin(arr, s, smallest);
    }
}

void Input_Heapmax(int arr[], int s){
    int last_n_l = (s/2) - 1;
   
    for(int i = last_n_l; i >= 0; i--)
        Heapifymax(arr, s, i);
}
int Print_HeapSortmax(int arr[], int s){
	int *sort_arr=new int[s];
    for (int i = 0; i < s; i++) {
    	swap(arr[i],arr[s-1]);
    	Heapifymax(arr, s, 0);
    	sort_arr[i]=arr[0];
        arr[0]=0;
        Heapifymax(arr, s, 0);
        cout<<sort_arr[i]<<" ";
    }
}


int main() {
    int N ;
    cout<<"Array length: ";
    cin>>N;
    int arr[N];
    cout<<"Array values: ";
    for(int i=0;i<N;i++)
    	cin>>arr[i];
    Input_Heapmax(arr,N);
    cout<<"MAX heap tree"<<endl;
    for(int i = 0; i<N; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout<<"\nMAX heap tree after sort"<<endl;
    Print_HeapSortmax(arr, N);
}

