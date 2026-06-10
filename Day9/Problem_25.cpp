
/* Data Structure :- LinkedLists(Singly Linked List)
Problem Title :- find the middlenode of the linked list
Problem Statement :- Given the head of a linked list of integers, determine the middle node of the linked list.
However, if the linked list has an even number of nodes, return the second middle node.
(Time Complexity :- O(n/2) and Space Complexity :- O(1))
*/


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at End
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Print Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Find Middle Node
Node* findMiddle(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtTail(head, x);
    }

    cout << "\nLinked List: ";
    printList(head);

    Node* middle = findMiddle(head);

    if (middle != NULL) {
        cout << "Middle Node = " << middle->data << endl;
    }

    return 0;
}