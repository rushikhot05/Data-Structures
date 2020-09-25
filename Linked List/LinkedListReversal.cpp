//Recursive approach to reverse a Linked List in c++
#include <iostream>
using namespace std;

//Linked LIst Node
struct Node {
    int data;
    struct Node *next;
    Node (int data){
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node *head;
    LinkedList(){
        head = NULL;
    }
    
    Node *reverse(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        //Reverse the rest list and put first element to the end
        Node *rest = reverse(head->next);
        head->next->next = head;
        
        head->next = NULL;
        
        //Fix the head pointer
        return rest;
    }
    //Function to print the Linked List
    void printList(){
        struct Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data){
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

//Driver Code
int main(){
    LinkedList l1;
    l1.push(20);
    l1.push(4);
    l1.push(15);
    l1.push(85);
    
    cout << "Given Linked List\n";
    l1.printList();
    
    l1.head = l1.reverse(l1.head);
    
    cout << "\nReversed Linked List \n";
    l1.printList();
    return 0;
}