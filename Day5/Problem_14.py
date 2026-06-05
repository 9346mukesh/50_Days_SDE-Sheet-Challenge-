"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Majority Element that occurs more than N/2 times
Problem Statement :- Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

(Time Complexity :- O(2n) and Space Complexity :- O(1))

"""

def findmajority(nums, n):
    count=0
    ele = None
    
    for i in range(n):
        if count ==0 :
            ele = nums[i]
            count +=1
        elif nums[i] == ele:
            count +=1
        else:
            count -=1
    
    count=0
    for i in range(n):
        if nums[i]== ele:
            count+=1
    
    if count > n//2:
        return ele
    
    return -1


if __name__ =="__main__":
    n = int(input().strip())
    nums = list(map(int, input().split()))
    
    MajorityElement = findmajority(nums,n);
    
    print(f"MajorityElement is: {MajorityElement}\n")