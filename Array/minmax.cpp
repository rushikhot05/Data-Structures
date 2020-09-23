//C++ program to find minimum and maximum element in an array
#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int max;
    int min;
};

struct Pair getMinMax(int arr[], int n){
    struct Pair minmax;
    int i;
    
    //If there is only one element, return same element as min and max
    if (n == 1){
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }
    
    //If there are more than 1 element, set min and max to 1st and 2nd element
    if (arr[0] > arr[1]){
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else{
        minmax.min = arr[0];
        minmax.max = arr[1];
    }
    
    for(i=2; i<n; i++){
        if(arr[i] < minmax.min){
            minmax.min = arr[i]; 
        }
        else if(arr[i] > minmax.min){
            minmax.max = arr[i];
        }
    }
    return minmax;
}
//Driver code
int main(){
    int arr[] = {2232, 5, 37, 123, 3, 214, 3389};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    struct Pair minmax = getMinMax(arr, arr_size);
    
    cout << "Minimum: " << minmax.min << endl;
    cout << "Maximum: " << minmax.max << endl;
    
    return 0;
}