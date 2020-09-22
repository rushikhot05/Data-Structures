#include<bits/stdc++.h>
using namespace std;

//Creates a difference array D[] for A[]  and returns 
//it after filling initial values

vector<int> initializeDiffArray(vector<int>& A){
    int n = A.size();
    
    vector<int> D(n+1);
    
    D[0] = A[0], D[n] = 0;
    for(int i=0; i<n; i++){
        D[i] = A[i] - A[i-1];
    }
    return D;
}

//Does range update
void update(vector<int>& D, int l, int r, int x){
    D[l] += x;
    D[r+1] -= x;
}

//Prints updated array
int printArray(vector<int>& A, vector<int>& D){
    for(int i=0; i<A.size(); i++){
        if(i==0){
            A[i] = D[i];
        }
        else{
            A[i] = D[i] + A[i - 1];
        }
        cout << A[i] << " ";
    }
    cout << endl;
}

//Driver Code
int main(){
    //Array to be updated
    vector<int> A = {5, 10, 15, 20};
    
    //Create and fill difference Array
    vector<int> D = initializeDiffArray(A);
    
    //Update the Array
    update(D, 0, 1, 5);
    printArray(A, D);
}