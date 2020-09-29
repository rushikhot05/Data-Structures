//Insertion of the node in circular linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data){
    if(last != NULL){
        return last;
    }
    Node *temp = new Node();
    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

struct Node *addBegin(struct Node *last, int data){
    if(last == NULL){
        return addToEmpty(last, data);
    }
    Node *temp = new Node();
    temp->data= data;
    temp->next = last->next;
    last->next = temp;
    
    return last;
}

struct Node *addEnd(struct Node *last, int data){
    if(last == NULL){
        return addToEmpty(last, data);
    }
    Node *temp = new Node();
    temp->data= data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
    
    return last;
}

struct Node *addAfter(struct Node *last, int data, int item){
    if(last == NULL){
        return NULL;
    }
    struct Node *temp, *p;
    p = last->next;
    do{
        if(p->data == item){
            temp = new Node();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            
            if(p == last){
                last = temp;
            }
            return last;
        }
        p = p->next;
    } while(p != last->next);
    
    cout << item << "Unavailable in the list" << endl;
    return last;
}

void traverse(struct Node *last){
    struct Node *p;
    if(last == NULL){
        cout << "The list is empty." << endl;
        return ;
    }
    
    p = last->next;
    do{
        cout << p->data << " ";
        p = p->next;
    }
    while(p != last->next);
}

int main(){
    struct Node *last = NULL;
    
    last = addToEmpty(last, 12);
    last = addBegin(last, 41);
    last = addBegin(last, 36);
    last = addEnd(last, 31);
    last = addEnd(last, 74);
    last = addAfter(last, 69, 36);
    
    traverse(last);
    return 0;
    
}
































