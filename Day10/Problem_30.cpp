
/* Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Add two numbers represented as Linked Lists
Problem Statement :- Add two numbers represented as Linked Lists.
(Time Complexity :- O(max(m,n)) and Space Complexity :- O(max(m,n)+)1.
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

Node* insertatTail(Node* head, int val) {
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

Node* addtwonumbers(Node* head1, Node* head2) {

    Node* dummynode = new Node(-1);

    Node* current = dummynode;

    Node* temp1 = head1;
    Node* temp2 = head2;

    int carry = 0;

    while (temp1 != nullptr && temp2 != nullptr) {

        int total = temp1->data + temp2->data + carry;

        Node* nodedigit = new Node(total % 10);

        carry = total / 10;

        current->next = nodedigit;
        current = current->next;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr) {

        int total = temp1->data + carry;

        Node* nodedigit = new Node(total % 10);

        carry = total / 10;

        current->next = nodedigit;
        current = current->next;

        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {

        int total = temp2->data + carry;

        Node* nodedigit = new Node(total % 10);

        carry = total / 10;

        current->next = nodedigit;
        current = current->next;

        temp2 = temp2->next;
    }

    if (carry > 0) {
        current->next = new Node(carry);
    }

    return dummynode->next;
}

int main() {

    int m, n;

    cout << "Enter the number of elements in LL1: ";
    cin >> m;

    cout << "Enter the number of elements in LL2: ";
    cin >> n;

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        head1 = insertatTail(head1, x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head2 = insertatTail(head2, x);
    }

    cout << "\nOriginal Linked Lists:\n";
    printLL(head1);
    printLL(head2);

    Node* head3 = addtwonumbers(head1, head2);

    cout << "\nResultant Linked List:\n";
    printLL(head3);

    return 0;
}