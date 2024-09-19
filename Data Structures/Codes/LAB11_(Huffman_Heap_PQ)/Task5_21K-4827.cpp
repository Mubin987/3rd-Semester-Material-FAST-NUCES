#include <iostream>
using namespace std;
 
int P_Queue[20];
int size = -1;
int parent(int i){
 
    return (i - 1) / 2;
}

int left(int i){
 
    return ((2 * i) + 1);
}
 
int right(int i){
    return ((2 * i) + 2);
}
 
void shiftUp(int i){
    while (i > 0 && P_Queue[parent(i)] < P_Queue[i]) {
 
        swap(P_Queue[parent(i)], P_Queue[i]);
 
        i = parent(i);
    }
}
void shiftDown(int i){
    int maxIndex = i;
    int l = left(i);
 
    if (l <= size && P_Queue[l] > P_Queue[maxIndex]) {
        maxIndex = l;
    }
    int r = right(i);
 
    if (r <= size && P_Queue[r] > P_Queue[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(P_Queue[i], P_Queue[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p)
{
    size = size + 1;
    P_Queue[size] = p;
    shiftUp(size);
}
 
int extractMax()
{
    int tempmax = P_Queue[0];
 
    P_Queue[0] = P_Queue[size];
    size = size - 1;
    shiftDown(0);
    return tempmax;
}
 
void changePriority(int i, int p)
{
    int oldp = P_Queue[i];
    P_Queue[i] = p;
 
    if (p > oldp) {
        shiftUp(i);
        return;
    }
    shiftDown(i);
}
int main()
{
    insert(15);
    insert(20);
    insert(14);
    insert(30);
    insert(48);
    insert(8);
    insert(12);
    insert(13);
    insert(8);
 
    int i = 0;
    cout << "Priority Queue : ";
    while (i <= size) {
        cout << P_Queue[i] << " ";
        i++;
    }
 
    cout << "\nNode with maximum priority : "<<P_Queue[0]<< "\n";
    extractMax();
    cout << "After Dequeue : ";
    int j = 0;
    while (j <= size) {
        cout << P_Queue[j] << " ";
        j++;
    }
    cout << "\n";
    changePriority(4, 50);
    cout << "After priority change : ";
    int k = 0;
    while (k <= size) {
        cout << P_Queue[k] << " ";
        k++;
    }
}
