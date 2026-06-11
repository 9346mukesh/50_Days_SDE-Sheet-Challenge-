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
        cout<<"Empty List\n";
        return;
    }

    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }

    cout<<"nullptr\n";
}

Node* reverse(Node* head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node* findknode(Node* head, int k){

    Node* temp = head;

    k--;

    while(temp != nullptr && k > 0){
        temp = temp->next;
        k--;
    }

    return temp;
}

Node* reverseKgroups(Node* head, int k){

    if(head == nullptr || head->next == nullptr || k == 1){
        return head;
    }

    Node* temp = head;
    Node* prevLast = nullptr;

    while(temp != nullptr){

        Node* kthNode = findknode(temp, k);

        if(kthNode == nullptr){

            if(prevLast != nullptr){
                prevLast->next = temp;
            }

            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;

        Node* newHead = reverse(temp);

        if(temp == head){
            head = newHead;
        }
        else{
            prevLast->next = newHead;
        }

        prevLast = temp;
        temp = nextNode;
    }

    return head;
}

int main(){

    int n;
    cout<<"Enter Size of Linked List:\n";
    cin>>n;

    Node* head = nullptr;

    cout<<"Enter Elements:\n";

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        head = insertattail(head,x);
    }

    int k;
    cout<<"Enter K Value:\n";
    cin>>k;

    cout<<"\nOriginal Linked List:\n";
    printLL(head);

    head = reverseKgroups(head,k);

    cout<<"\nLinked List After Reversing in K Groups:\n";
    printLL(head);

    return 0;
}