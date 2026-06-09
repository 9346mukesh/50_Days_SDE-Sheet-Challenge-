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


def merge_sorted_lists(head1, head2):

    dummy = Node(-1)
    tail = dummy

    t1 = head1
    t2 = head2

    while t1 and t2:

        if t1.data <= t2.data:
            tail.next = t1
            t1 = t1.next
        else:
            tail.next = t2
            t2 = t2.next

        tail = tail.next

    if t1:
        tail.next = t1

    if t2:
        tail.next = t2

    return dummy.next


# Input List 1
n1 = int(input("Enter size of List1: "))
head1 = None

print("Enter List1 elements:")
for _ in range(n1):
    x = int(input())
    head1 = insert_at_tail(head1, x)

# Input List 2
n2 = int(input("Enter size of List2: "))
head2 = None

print("Enter List2 elements:")
for _ in range(n2):
    x = int(input())
    head2 = insert_at_tail(head2, x)

print("\nList1:")
print_ll(head1)

print("List2:")
print_ll(head2)

merged_head = merge_sorted_lists(head1, head2)

print("\nMerged Sorted List:")
print_ll(merged_head)