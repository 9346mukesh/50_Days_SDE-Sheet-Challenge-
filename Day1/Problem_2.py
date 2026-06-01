"""
Data Structure :- Arrays (1-D & 2-D Arrays)
Problem Name :- Next Permutation

Problem Statement :-
Find the next lexicographically (dictionary order) greater
permutation of a given array of integers.

Time Complexity :- O(n)
Space Complexity :- O(1)
"""

def next_permutation(arr):
    n = len(arr)
    index = -1

    # Find the breaking point
    for i in range(n - 2, -1, -1):
        if arr[i] < arr[i + 1]:
            index = i
            break

    # Edge Case:
    # If no breaking point exists, the given permutation is the last permutation.
    # Return the first permutation by reversing the entire array.
    if index == -1:
        arr.reverse()
        return arr

    # Find the element just greater than arr[index] and swap
    for i in range(n - 1, index, -1):
        if arr[i] > arr[index]:
            arr[i], arr[index] = arr[index], arr[i]
            break

    # Reverse the suffix to get the next permutation
    arr[index + 1:] = reversed(arr[index + 1:])

    return arr


if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().split()))

    ans = next_permutation(arr)

    for num in ans:
        print(num, end=" ")