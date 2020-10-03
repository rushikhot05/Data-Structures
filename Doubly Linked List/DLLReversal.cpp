//Circular Linked List Reversal
#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node *next;
    Node *prev;
};

void reverse(Node **head_ref){
    Node *temp = NULL;
    Node *current = *head_ref;
    
    //Swap prev and next for all the node of doubly linked list
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    //Check if the list is empty or has only one Node
    if(temp != NULL){
        *head_ref = temp->prev;
    }
}

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

void printList(Node *node)  
{  
    while(node != NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}

int main(){
    Node *head = NULL;
    push(&head, 14);
    push(&head, 96);
    push(&head, 84);
    push(&head, 19);
    push(&head, 35);
    push(&head, 74);
    
    cout << "Original Doubly Linked List:" << endl;
    printList(head);
    
    reverse(&head);
    cout << "\nReversed Doubly linked list:" << endl;
    printList(head);
    return 0;
}