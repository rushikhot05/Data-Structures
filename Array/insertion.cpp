#include <iostream>
using namespace std;

//Function to insert element in array at given position

int *insertX(int n, int arr[], int x, int pos){
    int i;
    n++; //Increase size of the array
    //Shift elements forward
    for(i=n; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    
    //Insert x at pos
    arr[pos-1] = x;
    
    return arr;
}

//Driver Code
int main (){
    int i, x, pos, n = 10;
    int arr[n] = {1, 4, 5, 2, 45, 7, 43, 76, 23, 69};
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    //Element to be inserted
    x = 10;
    
    //Position at which element is to be inserted
    pos = 2;
    
    //Insert x at pos
    insertX(n, arr, x, pos);
    
    //Print the updated array
    for(int i=0; i< n+1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}