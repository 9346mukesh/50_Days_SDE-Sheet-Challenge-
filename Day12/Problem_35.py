"""
Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Check if the given Linked List is Palindrome
Problem Statement :- Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. 
Return true if it forms a palindrome, otherwise, return false.
(Time Complexity :- O(n)) and Space Complexity :- O(1).
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
    while temp.next:
        temp = temp.next

    temp.next = new_node
    return head


def print_ll(head):
    temp = head

    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


def reverse_ll(head):
    prev = None
    curr = head

    while curr:
        front = curr.next
        curr.next = prev
        prev = curr
        curr = front

    return prev


def is_palindrome(head):
    if head is None or head.next is None:
        return True

    # Find middle node
    slow = head
    fast = head

    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next

    # Reverse second half
    second_half = reverse_ll(slow.next)

    first = head
    second = second_half

    palindrome = True

    while second:
        if first.data != second.data:
            palindrome = False
            break

        first = first.next
        second = second.next

    # Restore original list
    slow.next = reverse_ll(second_half)

    return palindrome



if __name__ == "__main__":
    n = int(input("Enter number of nodes: "))

    arr = list(map(int, input("Enter elements: ").split()))

    head = None

    for x in arr:
        head = insert_at_tail(head, x)

    print("\nLinked List:")
    print_ll(head)

    if is_palindrome(head):
        print("Linked List is a Palindrome")
    else:
        print("Linked List is NOT a Palindrome")