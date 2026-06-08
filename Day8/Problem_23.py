"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count the number of subarrays with given xor K
Problem Statement :-  Given an array of integers and an integer K, find the total number of subarrays having XOR of their elements as K.
(Time Complexity :- O(n^2) and Space Complexity :- O(1))
(Brute Force)

"""

def count_subarray_with_xor_k(nums, k):
    count = 0
    n = len(nums)

    for i in range(n):
        xor_val = 0

        for j in range(i, n):
            xor_val ^= nums[j]

            if xor_val == k:
                count += 1

    return count


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    k = int(input())

    ans = count_subarray_with_xor_k(nums, k)
    print(ans)