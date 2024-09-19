#include<iostream>
using namespace std;
int NextGap(int);
void combSort(int array[], int n)
{
    int gap = n;
 
    bool swaped = 1;
    while (gap != 1 || swaped == 1)
    {
        gap = NextGap(gap);
 
        swaped = 0;
        for (int i=0; i<n-gap; i++)
        {
            if (array[i] > array[i+gap])
            {
                swap(array[i], array[i+gap]);
                swaped = 1;
            }
            	
        }
    }
}
int NextGap(int gap)
{
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
int main()
{
    int arr[] = {49, 11, 24, 44, 29, 27, 2, 22, 28};
    int n = sizeof(arr)/sizeof(int);
 
    combSort(arr, n);
 
    cout<<"Ascending order: "<<endl;
    for (int i=0; i<n; i++)
        cout<< arr[i]<<",";
 	cout<<"\n\nDescending order: "<<endl;
    for (int i=n-1; i>=0; i--)
        cout<< arr[i]<<",";
    return 0;
}
