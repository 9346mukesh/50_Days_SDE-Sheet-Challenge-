"""   Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Duplicate Number
Problem Statement :- Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.
*/

TC : O(n) and SC : O(1)

"""



"""
def find_duplicate(nums):

    nums.sort()

    for i in range(len(nums) - 1):

        if nums[i] == nums[i + 1]:

            return nums[i]

    return -1


"""

"""
def find_duplicate(nums):

    seen = set()

    for num in nums:

        if num in seen:

            return num

        seen.add(num)

    return -1

"""

"""
def find_duplicate(nums):

    n = len(nums)

    for i in range(n):

        for j in range(i + 1, n):

            if nums[i] == nums[j]:

                return nums[i]

    return -1
"""


def find_duplicate(nums):
    slow = nums[0]
    fast = nums[0]

    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]

        if slow == fast:
            break

    slow = nums[0]

    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]

    return slow

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    
    print("Duplicate Number is:", find_duplicate(nums))