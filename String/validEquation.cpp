//C++ Program to check if given equation as string is a valid equation
#include<bits/stdc++.h>
using namespace std;

//Function to check the validity of equation
bool isValid(string str){
    int k = 0;
    string operands[5] = {};
    char operators[4];
    long ans = 0, ans1 = 0, ans2 = 0;
    
    for(int i = 0; i< str.length(); i++){
        if(str[i] != '+' && str[i] != '=' && str[i] != '-'){
            operands[k] += str[i];
        }
        else{
            operators[k] += str[i];
            
            if(k == 1){
                if(operators[k-1] == '+'){
                    ans += stol(operands[k-1]) + stol(operands[k]);
                }
                if(operators[k-1] == '-'){
                    ans += stol(operands[k-1]) - stol(operands[k]);
                }
            }
            if(k == 2){
                if(operators[k-1] == '+'){
                    ans1 += ans + stol(operands[k]);
                }
                if(operators[k-1] == '-'){
                    ans1 += ans - stol(operands[k]);
                }
            }
            if(k == 3){
                if(operators[k-1] == '+'){
                    ans2 += ans1 + stol(operands[k]);
                }
                if(operators[k-1] == '-'){
                    ans2 += ans1 - stol(operands[k]);
                }
            }
            k++;
        }
    } 
    if(ans2 == stol(operands[4])){
        return true;
    }
    else{
        return false;
    }
}

//Driver Code
int main(){
    string str = "1+2+3+4=11";
    if(isValid(str)){
        cout << "Valid";
    }
    else{
        cout << "Invalid";
    }
    return 0;
}