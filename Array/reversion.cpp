//Recursive approach to reverse the array
#include<bits/stdc++.h>
using namespace std;

//Function to reverse the arr[] from start to end
void reverseArray(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    
    int temp = arr[start];
    arr[start]  = arr[end];
    arr[end] = temp;
    
    //Recursive function calling
    reverseArray(arr, start + 1, end - 1);
}

//Printing the array
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Driver Code
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    //Printing Original Array
    printArray(arr, 10);
    //Calling reverse function
    reverseArray(arr, 0, 9);
    
    cout << "Reversed array is " << endl;
    printArray(arr, 10);
    
    return 0;
}
