
/* Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Starting point of loop in a Linked List
Problem Statement :- Given the head of a linked list that may contain a cycle, return the starting point of that cycle. 
If there is no cycle in the linked list return null.
(Time Complexity :- O(n) and Space Complexity :- O(1))
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
        cout << "Empty List\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

Node* detectLoopStart(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main() {
    int n;
    cout << "Enter size of linked list: ";
    cin >> n;

    Node* head = nullptr;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtTail(head, x);
    }

    // Store all nodes for testing
    vector<Node*> nodes;
    Node* temp = head;
    while (temp != nullptr) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    int pos;
    cout << "Enter position to create loop (-1 for no loop): ";
    cin >> pos;

    if (pos >= 0 && pos < n) {
        nodes[n - 1]->next = nodes[pos];
    }

    Node* loopNode = detectLoopStart(head);

    if (loopNode) {
        cout << "Loop starts at node: " << loopNode->data << endl;
    } else {
        cout << "No Loop Present" << endl;
    }

    return 0;
}