
/* Data Structure :- LinkedLists(Single Linked List)
Problem Title :- Remove N-th node from the end of a Linked List
Problem Statement :-  Given a linked list and an integer N, 
the task is to delete the Nth node from the end of the linked list and print the updated linked list.
(Time Complexity :- O(n) and Space Complexity :- O(n))
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* insertatTail(Node* head, int val){
    Node* newNode = new Node(val);
    
    if(head == nullptr){
        return newNode;
    }
    
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLL(Node* head){
    if(head == nullptr){
        cout<<"Empty Linkedlist\n";
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullptr\n";
    return;
}


Node* remove_nth_Nodefromend(Node* head, int n){

    if(head == nullptr){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(n > 0 && fast != nullptr){
        fast = fast->next;
        n--;
    }

    // Delete head node
    if(fast == nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}

int main(){
    int m;
    cout<<"Enter the Noof elements in LL: ";
    cin>>m;
    
    Node* head =nullptr;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        head = insertatTail(head, x);
    }
    
    printLL(head);
    int n;
    cout<<"Nthe node for End to be delete: \n";
    cin>>n;
    head = remove_nth_Nodefromend(head, n);
    
    printLL(head);
    
    return 0;
}