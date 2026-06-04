"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count inversions in an array
Problem Statement :- Given an array of N integers, count the inversion of the array.

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

(Time Complexity :- O(n^2) and Space Complexity :- O(1))

"""


def countinversion(nums, n):
    cnt=0
    for i in range(n-1):
        for j in range(i+1, n):
            if nums[j]<nums[i]:
                cnt+=1
    
    return cnt




if __name__ == "__main__":

    n = int(input().strip())
    nums=list(map(int, input().split()))

    print(countinversion(nums, n))
