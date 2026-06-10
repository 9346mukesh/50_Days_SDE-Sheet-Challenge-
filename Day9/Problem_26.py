""" 
Data Structure :- Linked List(Single Linked List)
Problem Title :- Reverse a Linked List
Problem Statement :-Given the head of a singly linked list, write a program to reverse the linked list,
and return the head pointer to the reversed list.
(Time Complexity :- O(n) and Space Complexity :- O(1))

"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def insert_at_tail(head, val):
    new_node = Node(val)

    if head is None:
        return new_node
    temp = head
    while temp.next is not None:
        temp = temp.next
    temp.next = new_node
    return head


def print_ll(head):
    if head is None:
        print("Empty Linked List")
        return
    
    temp = head
    while temp is not None:
        print(temp.data, end=" -> ")
        temp = temp.next
        
    print("None")


def reverse_ll(head):
    if head is None or head.next is None:
        return head

    prev = None
    curr = head

    while curr is not None:
        front = curr.next
        curr.next = prev
        prev = curr
        curr = front
    return prev

if __name__ == "__main__":
    n = int(input("Enter No.of elements/Nodes: "))
    head = None
    print("Enter elements:")
    for _ in range(n):
        x = int(input())
        head = insert_at_tail(head, x)
    
    print("\nOriginal Linked List:")
    print_ll(head)
    rev_head = reverse_ll(head)
    print("\nReversed Linked List:")
    print_ll(rev_head)

    