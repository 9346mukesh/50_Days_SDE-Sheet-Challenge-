
/* Data Structure :- Linked Lists(Single Linked Lists)
Problem Title :- Delete given node in a Linked List : O(1) approach
Problem Statement :-Write a function to delete a node in a singly linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
(Time Complexity :- O(1) and Space Complexity :- O(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void printLL(Node* head) {
    if (head == nullptr) {
        cout << "Empty Linked List\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

void deleteNode(Node* node) {
    // Cannot delete last node using this method
    if (node == nullptr || node->next == nullptr) {
        cout << "Deletion not possible!\n";
        return;
    }

    Node* temp = node->next;

    node->data = temp->data;
    node->next = temp->next;

    delete temp;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    Node* head = nullptr;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtTail(head, x);
    }

    cout << "\nOriginal Linked List:\n";
    printLL(head);

    int pos;
    cout << "\nEnter position of node to delete (1-based index): ";
    cin >> pos;

    Node* node = head;

    for (int i = 1; i < pos && node != nullptr; i++) {
        node = node->next;
    }

    if (node == nullptr) {
        cout << "Invalid position!\n";
    } else {
        deleteNode(node);

        cout << "\nLinked List after deletion:\n";
        printLL(head);
    }

    return 0;
}