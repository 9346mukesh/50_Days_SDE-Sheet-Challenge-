
/* Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Check if the given Linked List is Palindrome
Problem Statement :- Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. 
Return true if it forms a palindrome, otherwise, return false.
(Time Complexity :- O(n)) and Space Complexity :- O(1).
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

Node* insertAtTail(Node* head, int val){
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
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

bool isPalindrome(Node* head){
    if(head == nullptr || head->next == nullptr){
        return true;
    }

    // Find middle node
    Node* slow = head;
    Node* fast = head;

    while(fast->next != nullptr &&
          fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* secondHalf = reverseLL(slow->next);

    Node* first = head;
    Node* second = secondHalf;

    bool palindrome = true;

    while(second != nullptr){
        if(first->data != second->data){
            palindrome = false;
            break;
        }

        first = first->next;
        second = second->next;
    }

    // Restore original list
    slow->next = reverseLL(secondHalf);

    return palindrome;
}

int main(){

    int n;
    cin >> n;

    Node* head = nullptr;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        head = insertAtTail(head, x);
    }

    printLL(head);

    if(isPalindrome(head)){
        cout << "Linked List is a Palindrome\n";
    }
    else{
        cout << "Linked List is NOT a Palindrome\n";
    }

    return 0;
}