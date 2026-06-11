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


def detect_loop_start(head):
    if head is None or head.next is None:
        return None

    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:

            slow = head

            while slow != fast:
                slow = slow.next
                fast = fast.next

            return slow

    return None


if __name__ == "__main__":
    n = int(input("Enter size of linked list: "))

    head = None
    nodes = []

    print("Enter elements:")
    for _ in range(n):
        x = int(input())
        head = insert_at_tail(head, x)

    temp = head
    while temp is not None:
        nodes.append(temp)
        temp = temp.next

    pos = int(input("Enter position to create loop (-1 for no loop): "))

    if pos != -1 and 0 <= pos < n:
        nodes[-1].next = nodes[pos]

    loop_node = detect_loop_start(head)

    if loop_node:
        print("Loop starts at node:", loop_node.data)
    else:
        print("No Loop Present")