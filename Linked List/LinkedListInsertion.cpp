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

/*Given a node prev_node, insert a new node
after the given prev_node*/
/*Time complexityof insertAfter()-: O(1)*/
void insertAfter(struct Node *prev_node, int new_data)
{
  //Check if the given prev_node is NULL
  if (prev_node == NULL)
    {
      cout << "The given previous node cannot be NULL";
      return;
    }

  //Allocate new Node
  Node *new_node = new Node();

  //Putting new data
  new_node->data = new_data;

  //making next of new node as next of prev_node
  new_node->next = prev_node->next;

  //Moving the next of prev_node as new_node
  prev_node->next = new_node;
}

/*Given a reference (pointer to pointer)to the head
of a list and an int, append a new node at the end*/
void append(struct Node **head_ref1, int new_data){
    //Allocating Node
    Node *new_node = new Node();
    
    Node *last = *head_ref1;
    
    //Putting in the data
    new_node->data = new_data;
    
    //This new node is going to be the last node
    //so make next of it is NULL
    new_node->next = NULL;
    
    //If the linked list is empty, then make new node as head
    if(*head_ref1 == NULL){
        *head_ref1 = new_node;
        return;
    }
    
    //Else traverse till the last node
    while(last->next != NULL)
        last = last->next;
        
    //Change the next of last node
    last->next = new_node;
    return;
}

//Driver Code
int main() 
{
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;

  //Allocating three nodes in heap
  head = new Node ();
  second = new Node ();
  third = new Node ();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  //Insert 0 at the beginning
  push(&head,0);
  
  //Insert 5 at the end
  append(&head, 5);
  
  //Insert 4 after 3
  insertAfter(head->next, 4);
  
  cout<<"The Linked List is: ";
  printList(head);

  return 0;
}
