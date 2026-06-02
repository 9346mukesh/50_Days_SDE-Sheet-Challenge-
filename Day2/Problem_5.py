""" Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Kadane's Algorithm : Maximum Subarray Sum in an Array
Problem Statement :- "Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

(Time Complexity :- O(n) and Space Complexity :- O(1))

"""


"""

def Max_subarray_sum(nums):
    n = len(nums)
    max_sum = float('-inf')
    current_sum = 0
    for i in range(n):
        current_sum += nums[i]
        max_sum = max(max_sum, current_sum)
        if current_sum < 0:
            current_sum = 0
    return max_sum

"""

def Max_subarray_sum(nums):
    n=len(nums)
    current_sum = nums[0]
    max_sum = nums[0]
    
    for i in range(1,n):
        current_sum = max(current_sum + nums[i], nums[i])
        max_sum = max(max_sum, current_sum)
    
    return max_sum




if __name__ == "__main__":
    n = int(input().strip());
    nums = list(map(int, input().split()))
    maxsubarraysum = Max_subarray_sum(nums)
    
    print(maxsubarraysum)