class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Insert at End
def insert_at_tail(head, val):

    new_node = Node(val)

    if head is None:
        return new_node

    temp = head

    while temp.next:
        temp = temp.next

    temp.next = new_node

    return head


# Print Linked List
def print_list(head):

    temp = head

    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


# Find Middle Node
def find_middle(head):

    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    return slow


# Main
n = int(input("Enter number of nodes: "))

head = None

print("Enter elements:")

for _ in range(n):
    x = int(input())
    head = insert_at_tail(head, x)

print("\nLinked List:")
print_list(head)

middle = find_middle(head)

if middle:
    print("Middle Node =", middle.data)