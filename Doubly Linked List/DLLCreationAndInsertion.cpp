//Insertion in the doubly linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, int new_data){
    //Allocate Node
    Node *new_node = new Node();
    //Putting in the data
    new_node->data = new_data;
    //Making next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    //Changing prev of head node to new node
    if((*head_ref) != NULL){
        (*head_ref)->prev  = new_node;
    }
    //Moving head to point to the new node
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data){
    if(prev_node == NULL){
        cout << "Given previous node cannot be NULL";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

void insertBefore(Node **head_ref, Node *next_node, int new_data){
    if(next_node == NULL){
        cout << "Given previous node cannot be NULL";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;
    if(new_node->prev != NULL){
        new_node->prev->next = new_node;
    }
    else{
        (*head_ref) = new_node;
    }
}
void append(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node();  
  
    Node* last = *head_ref; /* used in step 5*/
    new_node->data = new_data;  
    new_node->next = NULL;  
    if (*head_ref == NULL) 
    {  
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;  
    }  
    while (last->next != NULL){
       last = last->next; 
    }  
    last->next = new_node;  
    new_node->prev = last;  
  
    return;  
}  

void printList(Node *node){
    Node *last;
    cout << "\nTraversal in forward direction \n";
    while(node != NULL){
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    
    cout << "\nTraversal in backward direction \n";
    while(last != NULL){
        cout << " " << last->data << " ";
        last = last->prev;
    }
}

int main(){
    Node *head = NULL;
    append(&head, 32);
    push(&head, 14);
    push(&head, 96);
    append(&head, 69);
    insertAfter(head->next, 45);
    insertBefore(&head, head->next, 26);
    cout << "Created Doubly Linked List:" << endl;
    printList(head);
    return 0;
}