""" Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Sort an array of 0s, 1s and 2s
Problem Statement :- Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

(Time Complexity :- O(n) and Space Complexity :- O(1))

"""




def sort_zeros_ones_twos(nums):
    low, mid, high = 0, 0, len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1

        elif nums[mid] == 1:
            mid += 1

        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1


if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int, input().split()))

    sort_zeros_ones_twos(nums)

    print(*nums)