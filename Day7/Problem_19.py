"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Two Sum :  Return All Unique pairs with given sum exists
Problem Statement :- Given an integer array nums of size n, return all unique pairs that sum up to the target value.


"""

# Time Complexity: O(n)
# Space Complexity: O(n). we need the index of the elements so we need to store them in the map of SC : O(n) in worst case

def twosum(nums, n, target):
    mpp = {}

    for i in range(n):
        remaining = target - nums[i]

        idx = mpp.get(remaining)

        if idx is not None:
            return [idx, i]

        mpp[nums[i]] = i

    return []


if __name__ == "__main__":
    n = int(input())

    nums = list(map(int, input().split()))

    target = int(input())

    ans = twosum(nums, n, target)

    if len(ans) == 0:
        print("Sum of any two elements in array is not equal to target")
    else:
        print(f"sum of {nums[ans[0]]} at index {ans[0]} and {nums[ans[1]]} at index {ans[1]} is equal to target")