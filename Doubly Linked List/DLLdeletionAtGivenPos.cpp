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

void deleteNode(struct Node **head_ref, struct Node *del){
    //base case
    if(*head_ref == NULL || del == NULL){
        return;
    }
    
    //if node to be deleted is head Node
    if(*head_ref == del){
        *head_ref = del->next;
    }
    //Change next only if node to be deleted is not last
    if(del->next != NULL){
        del->next->prev = del->prev;
    }
    //Change prev only if node to be selected is not first
    if(del->prev != NULL){
        del->prev->next = del->next;
    }
    free(del);
}

void deleteNodeAtGivenPos(struct Node **head_ref, int n){
    if(*head_ref == NULL || n <= 0){
        return;
    }
    
    Node *current = *head_ref;
    
    for(int i=1; current!=NULL && i<n; i++){
        current = current->next;
    }
    
    if(current == NULL){
        return;
    }
    
    deleteNode(head_ref, current);
}

void printList(struct Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    push(&head, 12);
    push(&head, 17);
    push(&head, 35);
    push(&head, 10);
    push(&head, 2);
    push(&head, 96);
    cout << "Doubly Linked list before deletion:" << endl;
    printList(head);
    int n = 4;
    deleteNodeAtGivenPos(&head, n);
    cout << "\nDoubly Linked List after deletion: " << endl;
    printList(head);
    return 0;
}