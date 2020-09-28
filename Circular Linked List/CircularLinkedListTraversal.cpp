//Circular Linked List Traversal
#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node *next;
};

//Push function to push elements into circular linked list
void push(Node **head_ref, int data){
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
    
    if(*head_ref != NULL){
        while(temp->next != *head_ref){
            temp = temp->next; 
        }
        temp->next = ptr1;
    }
    else{
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}
//Print the circular linked list
void printList(Node *head){
    Node *temp = head;
    if(head != NULL){
        do {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != head);
    }
}

//Driver Code
int main(){
    Node *head = NULL;
    
    push(&head, 51);
    push(&head, 36);
    push(&head, 78);
    push(&head, 12);
    push(&head, 72);
    push(&head, 69);
    
    cout << "Circular Linked List: ";
    printList(head);
    return 0;
}