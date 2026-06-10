"""
Data Structure :- Linked Lists(Single Linked Lists)
Problem Title :- Delete given node in a Linked List : O(1) approach
Problem Statement :-Write a function to delete a node in a singly linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
(Time Complexity :- O(1) and Space Complexity :- O(n))

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


def deleteNode(node):
    # Cannot delete the last node
    if node is None or node.next is None:
        print("Deletion not possible")
        return

    temp = node.next

    node.data = temp.data
    node.next = temp.next

    del temp


if __name__ == "__main__":

    m = int(input("Enter the noof elements : \n"))

    head = None

    for i in range(m):
        x = int(input())
        head = insertattail(head, x)

    print("\nOriginal Linked List:")
    printLL(head)

    pos = int(input("\nEnter the position of node to delete : "))

    node = head

    for i in range(1, pos):
        if node is None:
            break
        node = node.next

    if node is None:
        print("Invalid Position")
    else:
        deleteNode(node)

    print("\nLinked List after deletion:")
    printLL(head)