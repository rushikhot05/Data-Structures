//Juggling Algorithm for array rotation by d elements
#include<bits/stdc++.h>
using namespace std;

//Function to get gcb of numbers a and b
int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

//Function to left rotate the array of size n by d elements
void leftRotate(int arr[], int d, int n){
    d = d % n; //To handle if d >=n
    int g_c_d = gcd(d, n);
    for(int i=0; i<g_c_d; i++){
        //move ith value
        int temp = arr[i];
        int j = i;
        
        while(1){
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
//Print the array
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

//Driver Code
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    leftRotate(arr, 5, n);
    printArray(arr, n);
    
    return 0;
}

























