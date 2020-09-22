/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->data = 1;     //Assigning data in  first node
    head->next = second;    //Link first node with the second node
    
    second->data = 2;   //Assigning data to second node
    second->next = third;       //Link second node to the third node
    
    third->data = 3;    //Assigning data to third node
    third->next = NULL;     //Link third node to NULL
    
    return 0;
}
