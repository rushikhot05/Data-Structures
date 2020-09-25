//#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

//Function to print contents of linked list
void printList(Node * n)
{
  while (n != NULL)
    {
      cout << n->data << " ";
      n = n->next;
    }
}


/* Given a referance (pointer to pointer)
to the head of a list an int, inserts a new
nodeon the front of the list.*/
/*Time complexity of push()-: O(1)*/
void push(Node ** head_ref, int new_data)
{
  //Allocate Node
  Node *new_node = new Node();

  //Putting the data
  new_node->data = new_data;

  //Making next of new node as head
  new_node->next = (*head_ref);

  //Moving the head to the point to the new Node
  (*head_ref) = new_node;
}
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position){
    //If linked list is empty
    if(*head_ref == NULL){
        return;
    }
    struct Node *temp = *head_ref;
    //If head need to be removed
    if(position == 0){
        *head_ref = temp->next; //Change head
        free(temp); //Free old head
        return;
    }
    //Find previous node of the node to be deleted
    for(int i=0; temp!= NULL && i<position-1; i++){
        temp = temp->next;
    }
    //If position is more than number of nodes
    if(temp == NULL || temp->next == NULL){
        return;
    }
    //Node temp->next is node to be deleted
    //Store pointerr to the next of the node to be deleted
    struct Node *next = temp->next->next;
    //Unlink the node from the linked list
    free(temp->next);
    
    temp->next = next;
}
//Driver Code
int main(){
    struct Node* head = NULL; 
  
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
  
    cout << "Created Linked List: "; 
    printList(head); 
    deleteNode(&head, 3); 
    cout << "\nLinked List after Deletion at position 3: "; 
    printList(head); 
    return 0; 
}