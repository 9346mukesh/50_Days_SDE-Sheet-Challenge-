"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count Reverse Pairs
Problem Statement :-Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
(Time Complexity :- O(n^2) and Space Complexity :- O(1))

"""


def count_reverse_pair(nums, n):
    count = 0

    for i in range(n - 1):
        for j in range(i + 1, n):
            if nums[i] > 2 * nums[j]:
                count += 1

    return count


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))

    print("No.of reverse pairs :", count_reverse_pair(nums, n))