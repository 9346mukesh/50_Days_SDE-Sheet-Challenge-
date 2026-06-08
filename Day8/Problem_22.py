
"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Length of the longest subarray with zero Sum
Problem Statement :-Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
(Time Complexity :- O(n) and Space Complexity :- O(n))

"""

def  longestsubarraywith_sumk(nums, n, k):

    longest = -1
    prefixmap= {}
    prefixsum=0

    for i in range(n):
        prefixsum+= nums[i]

        if prefixsum == k:
            longest = max(longest, i+1)

        if prefixsum-k in prefixmap:
            longest = max(longest, i-prefixmap[prefixsum-k])

        if prefixsum not in prefixmap:
            prefixmap[prefixsum] = i
    
    return longest






    """longest = -1
    for i in range(n):
        sum=0
        for j in range(i,n):
            sum+= nums[j]
            if sum == k:
                longest = max(longest, j-i+1)

    return longest """






## Largest Subarray with K sum

if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int, input().split()))

    k = int(input().strip())

    ans = longestsubarraywith_sumk(nums, n, k)

    if ans == -1:
        print(f"NO subarray have sum with {k}")
    else:
        print(f"Longest subarray with sum {k} is : {ans}")