
"""
Data Structure :- LinkedLists(Single Linked Lists)
Problem Title :- Reverse Linked List in groups of Size K
Problem Statement :- Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.
Do not change the values of the nodes, only change the links between nodes.
(Time Complexity :- O(n) and Space Complexity :- 0(1).

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
        print("Empty List")
        return

    temp = head

    while temp is not None:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


def reverse(head):

    if head is None or head.next is None:
        return head

    temp = head
    prev = None

    while temp is not None:
        front = temp.next
        temp.next = prev
        prev = temp
        temp = front

    return prev


def find_k_node(head, k):

    temp = head
    k -= 1

    while temp is not None and k > 0:
        temp = temp.next
        k -= 1

    return temp


def reverse_k_groups(head, k):

    if head is None or head.next is None or k == 1:
        return head

    temp = head
    prev_last = None

    while temp is not None:

        kth_node = find_k_node(temp, k)

        if kth_node is None:

            if prev_last is not None:
                prev_last.next = temp

            break

        next_node = kth_node.next
        kth_node.next = None

        new_head = reverse(temp)

        if temp == head:
            head = new_head
        else:
            prev_last.next = new_head

        prev_last = temp
        temp = next_node

    return head


if __name__ == "__main__":

    n = int(input("Enter Size of Linked List: "))

    head = None

    print("Enter Elements:")
    for _ in range(n):
        x = int(input())
        head = insert_at_tail(head, x)

    k = int(input("Enter K Value: "))

    print("\nOriginal Linked List:")
    print_ll(head)

    head = reverse_k_groups(head, k)

    print("\nLinked List After Reversing in K Groups:")
    print_ll(head)