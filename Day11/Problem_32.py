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


def intersection_of_2_nodes(head1, head2):

    if head1 is None or head2 is None:
        return None

    temp1 = head1
    temp2 = head2

    while temp1 != temp2:

        if temp1 is None:
            temp1 = head2
        else:
            temp1 = temp1.next

        if temp2 is None:
            temp2 = head1
        else:
            temp2 = temp2.next

    return temp1


if __name__ == "__main__":

    # Common Part
    common = Node(8)
    common.next = Node(10)
    common.next.next = Node(12)

    # Linked List 1
    head1 = None
    head1 = insert_at_tail(head1, 1)
    head1 = insert_at_tail(head1, 2)
    head1 = insert_at_tail(head1, 3)

    temp1 = head1
    while temp1.next is not None:
        temp1 = temp1.next

    temp1.next = common

    # Linked List 2
    head2 = None
    head2 = insert_at_tail(head2, 4)
    head2 = insert_at_tail(head2, 5)

    temp2 = head2
    while temp2.next is not None:
        temp2 = temp2.next

    temp2.next = common

    print("Linked List 1:")
    print_ll(head1)

    print("\nLinked List 2:")
    print_ll(head2)

    ans = intersection_of_2_nodes(head1, head2)

    if ans is not None:
        print(f"\nIntersection Node is : {ans.data}")
    else:
        print("\nNo Intersection Present")