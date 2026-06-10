
/* Data Structure :- Linked List(Single Linked List)
Problem Title :- Merge Two Sorted Lists
Problem Statement :-Given the heads of two sorted linked lists, merge the two lists and return the head pointer to the merged list.
(Time Complexity :- O(m+n) and Space Complexity :- O(1))
*/


#include <iostream>
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

// Insert at Tail
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

// Print Linked List
void printLL(Node* head) {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr" << endl;
}

// Merge Two Sorted Lists
Node* mergeSortedLists(Node* head1, Node* head2) {

    Node dummy(-1);
    Node* tail = &dummy;

    while (head1 != nullptr && head2 != nullptr) {

        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1 != nullptr) {
        tail->next = head1;
    }

    if (head2 != nullptr) {
        tail->next = head2;
    }

    return dummy.next;
}

int main() {

    int n1;
    cout << "Enter size of first sorted list: ";
    cin >> n1;

    Node* head1 = nullptr;

    cout << "Enter elements of first sorted list:\n";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        head1 = insertAtTail(head1, x);
    }

    int n2;
    cout << "Enter size of second sorted list: ";
    cin >> n2;

    Node* head2 = nullptr;

    cout << "Enter elements of second sorted list:\n";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        head2 = insertAtTail(head2, x);
    }

    cout << "\nFirst List:\n";
    printLL(head1);

    cout << "\nSecond List:\n";
    printLL(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);

    cout << "\nMerged Sorted List:\n";
    printLL(mergedHead);

    return 0;
}