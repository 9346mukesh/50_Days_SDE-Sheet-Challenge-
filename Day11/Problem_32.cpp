/* Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Find intersection of Two Linked Lists
Problem Statement :- Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
(Time Complexity :- O(2 × max(length of list1, length of list2)) and Space Complexity :- O(1).
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
        cout << "Empty List\n";
        return;
    }

    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

Node* intersectionof2nodes(Node* head1, Node* head2){

    if(head1 == nullptr || head2 == nullptr){
        return nullptr;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2){

        if(temp1 == nullptr){
            temp1 = head2;
        }
        else{
            temp1 = temp1->next;
        }

        if(temp2 == nullptr){
            temp2 = head1;
        }
        else{
            temp2 = temp2->next;
        }
    }

    return temp1;
}

int main(){

    // Common Part
    Node* common = new Node(8);
    common->next = new Node(10);
    common->next->next = new Node(12);

    // Linked List 1
    Node* head1 = nullptr;
    head1 = insertattail(head1, 1);
    head1 = insertattail(head1, 2);
    head1 = insertattail(head1, 3);

    Node* temp1 = head1;
    while(temp1->next != nullptr){
        temp1 = temp1->next;
    }
    temp1->next = common;

    // Linked List 2
    Node* head2 = nullptr;
    head2 = insertattail(head2, 4);
    head2 = insertattail(head2, 5);

    Node* temp2 = head2;
    while(temp2->next != nullptr){
        temp2 = temp2->next;
    }
    temp2->next = common;

    cout << "Linked List 1:\n";
    printLL(head1);

    cout << "\nLinked List 2:\n";
    printLL(head2);

    Node* ans = intersectionof2nodes(head1, head2);

    if(ans != nullptr){
        cout << "\nIntersection Node is : " << ans->data << "\n";
    }
    else{
        cout << "\nNo Intersection Present\n";
    }

    return 0;
}