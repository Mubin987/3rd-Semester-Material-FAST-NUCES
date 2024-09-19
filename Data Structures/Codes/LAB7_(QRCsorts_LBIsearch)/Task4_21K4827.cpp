#include <iostream>
using namespace std;
 
int interpolationsearch(int arr[], int lo, int hi, int x)
{
    
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
 
       
        int pos = lo+ (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        
      	if (arr[pos] == x)
            return pos;
 
      	else  if (arr[pos] < x)
            return interpolationsearch(arr, pos + 1, hi, x);
 
      
    	else if (arr[pos] > x)
            return interpolationsearch(arr, lo, pos-1, x);
    }
    return -1;
}
 
 
int main()
{
 
    int arr[10] = {20, 22, 24, 24, 26, 28, 30},n,x,index,lo,hi;
 
    x = 18;
    lo = 0;
    hi = 6;
    index = interpolationsearch(arr, lo, hi, x);
 	
    if (index == -1)
    	cout << "The element is not present"<<endl;
    else
        
        cout << "Element found at index " << index<<endl;
 	x = 20;
 	index = interpolationsearch(arr, lo, hi, x);
 	
    if (index == -1)
    	cout << "The element is not present";
    else
        
        cout << "Element found at index " << index;
    return 0;
}
