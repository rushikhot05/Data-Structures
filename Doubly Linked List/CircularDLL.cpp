//Doubly Circular LInked LIst
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

//Insert the node at the end
void insertAtEnd(struct Node **start, int value){
    //If list is empty
    if(*start == NULL){
        Node *new_node = new Node();
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
    }
    //If list is not empty
    else{
    Node *last = (*start)->prev;
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    }
}

//Insert the node at the beginning
void insertAtStart(struct Node **start, int value){
    struct Node *last = (*start)->prev;
    Node *new_node = new Node();
    new_node->data = value;
    
    new_node->next = *start;
    new_node->prev = last;
    
    last->next = (*start)->prev = new_node;
    *start = new_node;
}

//Insert the node after given node
void insertAfter(struct Node **start, int value1, int value2){
    Node *new_node = new Node();
    new_node->data = value1;
    
    struct Node *temp = *start;
    while(temp->data != value2){
        temp = temp->next;
    }
    struct Node *next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}

void printList(Node *start){
    struct Node *temp = start;
    cout << "\nTraversal in forward direction:" << endl;
    while (temp->next != start) 
    { 
        cout << temp->data << " ";
        temp = temp->next; 
    } 
    cout << temp->data << " "; 
  
    cout << "\nTraversal in reverse direction" << endl; 
    Node *last = start->prev; 
    temp = last; 
    while (temp->prev != last) 
    { 
        cout << temp->data << " ";
        temp = temp->prev; 
    } 
    cout << temp->data << " "; 
}

int main(){
    struct Node *start = NULL;
    insertAtEnd(&start, 15);
    insertAtStart(&start, 89);
    insertAtEnd(&start, 74);
    insertAtEnd(&start, 35);
    insertAfter(&start, 69, 89);
    cout << "Created circular doubly linked list: " << endl;
    printList(start);
    return 0;
}