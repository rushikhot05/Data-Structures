//Program to check if the array is sorted or not
//Using iteratice approach as it avoids usage of recursion stack space and recursion overhead

#include<bits/stdc++.h>
using namespace std;

bool sortedOrNot(int arr[], int n){
    if(n == 0 | n == 1){
        return true;
    }
    
    for(int i = 0; i<n; i++){
        if (arr[i -1] > arr[i]){
            return false;
        }
    }
    return true;
}

//Driver Code
int main(){
    int arr[] = {11, 13, 25, 64, 89, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(sortedOrNot(arr, n)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}