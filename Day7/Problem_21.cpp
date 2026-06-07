/* Data Structure :- Arrays(1-D & 2-D Arrays)
Longest Consecutive Sequence in an Array
Problem Statement :-Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
(Time Complexity :- O(n log n) and Space Complexity :- O(1))
*/


def longest_consecutive(nums):
    n = len(nums)

    if n == 0:
        return 0

    nums.sort()

    longest = 1
    current = 1
    last_smallest = float('-inf')

    for i in range(n):
        if last_smallest + 1 == nums[i]:
            current += 1
            last_smallest = nums[i]

        elif last_smallest == nums[i]:
            continue

        else:
            last_smallest = nums[i]
            longest = max(longest, current)
            current = 1

    longest = max(longest, current)

    return longest


"""
# Brute Force Approach

def linear_search(nums, target):
    for num in nums:
        if num == target:
            return True
    return False


def longest_consecutive(nums):
    n = len(nums)

    longest = 1

    for i in range(n):
        x = nums[i]
        current = 1

        while linear_search(nums, x + 1):
            x += 1
            current += 1

        longest = max(longest, current)

    return longest
"""


if __name__ == "__main__":
    n = int(input())

    nums = list(map(int, input().split()))

    longest_sequence = longest_consecutive(nums)

    print("Longest consecutive sequence in the given array is:",
          longest_sequence)