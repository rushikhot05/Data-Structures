#include<iostream>
using namespace std;

// This function removes an element x from arr[] and 
// returns new size after removal (size is reduced only 
// when x is present in arr[] 

int deleteElement(int arr[], int n, int x){
    //Search x in array
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == x){
            break;
        }
    }
    //If x found in array
    if(i < n){
        //Reduce size of an array and move all elements on space ahead
        n = n-1;
        for(int j=i; j<n; j++){
            arr[j] = arr[j+1];
        }
    }
    return n;
}

//Driver Code
int main(){
    int arr[] = {45, 57, 64, 32, 5, 36};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    
    //Delete x from arr
    n = deleteElement(arr, n, x);
    
    //Print updated array
    cout << "Modified array is \n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}