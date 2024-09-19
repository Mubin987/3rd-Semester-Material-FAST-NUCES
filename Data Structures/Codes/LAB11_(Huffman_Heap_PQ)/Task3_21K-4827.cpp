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
void Input_Heapmin(int arr[], int s){
    int last_n_l = (s/2) - 1;
   
    for(int i = last_n_l; i >= 0; i--)
        Heapifymin(arr, s, i);
}

int Deletemax(int arr[], int s){
    int lastElement = s - 1;
    arr[2] = arr[lastElement];
    s--;
    Heapifymax(arr, s, 2);
    return s;
}
int Deletemin(int arr[], int s){
    int lastElement = s - 1;
    arr[7] = arr[lastElement];
    s--;
    Heapifymin(arr, s, 7);
    return s;
}
void HeapSortmax(int arr[], int s){
     
    Input_Heapmax(arr, s);
 
    for (int i = s - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
 

        Heapifymax(arr, i, 0);
    }
}
void HeapSortmin(int arr[], int s){
     
    Input_Heapmin(arr, s);
 
    for (int i = s - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
 

        Heapifymin(arr, i, 0);
    }
}


int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int s = sizeof(arr)/sizeof(arr[0]);
    Input_Heapmax(arr,s);
    cout<<"MAX heap tree"<<endl;
    for(int i = 0; i<s; i++)
        cout << arr[i] << " ";
    cout << endl;
    s =Deletemax(arr, s);
    cout << "\nAfter Delete of 42: " << endl;
     for(int i = 0; i<s; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout<<"\nMAX heap tree after sort"<<endl;
    HeapSortmax(arr, s);
     for(int i = s-1; i>=0; i--)
        cout << arr[i] << " "; 
    Input_Heapmin(arr,s);
    cout<<"\n\nMIN heap tree"<<endl;
    for(int i = 0; i<s; i++)
        cout << arr[i] << " ";
    cout << endl;
    s =Deletemin(arr, s);
    cout << "\nAfter Delete of 35: " << endl;
     for(int i = 0; i<s; i++)
        cout << arr[i] << " ";
    
}

