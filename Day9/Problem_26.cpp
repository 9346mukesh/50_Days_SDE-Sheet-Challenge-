
/* Data Structure :- Linked List(Single Linked List)
Problem Title :- Reverse a Linked List
Problem Statement :-Given the head of a singly linked list, write a program to reverse the linked list,
and return the head pointer to the reversed list.
(Time Complexity :- O(n) and Space Complexity :- O(1))
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

Node* insertattail(Node* head, int val){

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
        cout << "Empty Linked List\n";
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

Node* reverseLL(Node* head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* prev = nullptr;
    Node* temp = head;

    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

int main(){

    int n;
    cout << "Enter No.of elements/Nodes: ";
    cin >> n;

    Node* head = nullptr;
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        head = insertattail(head, x);
    }

    cout << "\nOriginal Linked List:\n";
    printLL(head);

    Node* revhead = reverseLL(head);

    cout << "\nReversed Linked List:\n";
    printLL(revhead);

    return 0;
}