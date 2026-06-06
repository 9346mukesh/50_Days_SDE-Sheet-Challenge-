"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Majority Element that occurs more than N/3 times
Problem Statement :- Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/3 times in the array. The array is guaranteed to have a majority element.

(Time Complexity :- O(2n) and Space Complexity :- O(1))

"""


def find_majority_elements(nums):
    n = len(nums)

    ele1 = float('-inf')
    ele2 = float('-inf')
    count1 = 0
    count2 = 0

    # Find candidates
    for num in nums:
        if count1 == 0 and num != ele2:
            ele1 = num
            count1 += 1

        elif count2 == 0 and num != ele1:
            ele2 = num
            count2 += 1

        elif num == ele1:
            count1 += 1

        elif num == ele2:
            count2 += 1

        else:
            count1 -= 1
            count2 -= 1

    # Verify candidates
    count1 = 0
    count2 = 0

    for num in nums:
        if num == ele1:
            count1 += 1
        elif num == ele2:
            count2 += 1

    ans = []

    if count1 > n // 3:
        ans.append(ele1)

    if count2 > n // 3:
        ans.append(ele2)

    return ans


if __name__ == "__main__":
    n = int(input("Enter size of array: "))

    print("Enter array elements:")
    nums = list(map(int, input().split()))

    
    majority = find_majority_elements(nums)

    if not majority:
        print("No majority elements")
    else:
        print("Majority elements:", *majority)