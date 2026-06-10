"""
Data Structure :- LinkedLists(Single Linked List)
Problem Title :- Remove N-th node from the end of a Linked List
Problem Statement :-  Given a linked list and an integer N, 
the task is to delete the Nth node from the end of the linked list and print the updated linked list.
(Time Complexity :- O(n) and Space Complexity :- O(n))

"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def insertattail(head, val):
    newNode = Node(val)

    if head is None:
        return newNode

    temp = head
    while temp.next is not None:
        temp = temp.next

    temp.next = newNode
    return head


def printLL(head):
    if head is None:
        print("Empty Linked List")
        return

    temp = head
    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


def removenthnode(head, n):
    if head is None:
        return head

    slow = head
    fast = head

    while n > 0 and fast is not None:
        n -= 1
        fast = fast.next

    # Delete first node
    if fast is None:
        return head.next

    while fast.next is not None:
        fast = fast.next
        slow = slow.next

    deletenode = slow.next
    slow.next = slow.next.next
    del deletenode

    return head


if __name__ == "__main__":
    m = int(input("Enter the number of elements: "))

    head = None

    for _ in range(m):
        x = int(input())
        head = insertattail(head, x)

    print("\nOriginal Linked List:")
    printLL(head)

    n = int(input("\nEnter the Nth Node from End to Remove: "))

    head = removenthnode(head, n)

    print("\nUpdated Linked List:")
    printLL(head)