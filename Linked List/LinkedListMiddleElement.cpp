#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

//Function to find the middle element of the linked list
void printMiddle(struct Node *head){
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    
    if(head!= NULL){
        while (fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout << "Middle pointer is " << slow_ptr->data;
    }
}

//Push elements into the linked list
void push(struct Node **head_ref, int new_data){
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Print linked list
void printList(struct Node *ptr){
    while(ptr != NULL){
        cout << " " << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
//Driver Code
int main(){
    struct Node *head = NULL;
    push(&head, 2);
    push(&head, 54);
    push(&head, 21);
    push(&head, 8);
    push(&head, 78);
    push(&head, 35);
    push(&head, 11);
    printList(head);
    printMiddle(head);
    
    return 0;
}