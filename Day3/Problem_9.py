

"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Merge Two Sorted Arrays without ExtraSpace
Problem Statement :- Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

(Time Complexity :- O(m + n) and Space Complexity :- O(1))

"""

def merge_two_sorted_arrays(nums1, nums2):
    m = len(nums1)
    n = len(nums2)

    left = m - 1
    right = 0

    while left >= 0 and right < n:
        if nums1[left] > nums2[right]:
            nums1[left], nums2[right] = nums2[right], nums1[left]
            left -= 1
            right += 1
        else:
            break

    nums1.sort()
    nums2.sort()


if __name__ == "__main__":
    m, n = map(int, input().split())
    nums1 = list(map(int, input().split()))
    nums2 = list(map(int, input().split()))
    
    merge_two_sorted_arrays(nums1, nums2)
    
    print("Array 1:", *nums1)
    print("Array 2:", *nums2)