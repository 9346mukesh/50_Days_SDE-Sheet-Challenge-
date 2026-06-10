"""
Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Add two numbers represented as Linked Lists
Problem Statement :- Add two numbers represented as Linked Lists.
(Time Complexity :- O(max(m,n)) and Space Complexity :- O(max(m,n)+)1.

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

def addtwonumbers(head1, head2):
    dummynode = Node(-1)
    current = dummynode
    temp1 = head1
    temp2 = head2

    carry = 0
    while temp1 is not None and temp2 is not None:
        total = temp1.data + temp2.data + carry
        nodedigit = Node(total % 10)
        carry = total // 10
        current.next = nodedigit
        current = current.next
        temp1 = temp1.next
        temp2 = temp2.next

    while temp1 is not None:
        total = temp1.data + carry
        nodedigit = Node(total % 10)
        carry = total // 10
        current.next = nodedigit
        current = current.next
        temp1 = temp1.next

    while temp2 is not None:
        total = temp2.data + carry
        nodedigit = Node(total % 10)
        carry = total // 10
        current.next = nodedigit
        current = current.next
        temp2 = temp2.next

    if carry > 0:
        current.next = Node(carry)

    return dummynode.next

if __name__ == "__main__":
    m = int(input("Enter the number of elements in LL1: "))
    n = int(input("Enter the number of elements in LL2: "))
    head1 = None
    head2 = None

    for _ in range(m):
        x1 = int(input())
        head1 = insertattail(head1, x1)
        
    for _ in range(n):
        x2 = int(input())
        head2 = insertattail(head2, x2)

    print("\nOriginal Linked Lists:")
    printLL(head1)
    printLL(head2)
    
    head3 = addtwonumbers(head1, head2);
    

    print("\nResultant Linked List:")
    printLL(head3)