"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- 4 Sum | Find Quads that add up to a target value
Problem Statement :- Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
Note: a, b, c and d are also distinct and lies between 0 to n-1 (both inclusive).

(Time Complexity :- O(n log n) + O(n^3)and Space Complexity :- O(1))

"""




def four_sum(nums, target):
    nums.sort()
    n = len(nums)
    ans = []

    for i in range(n):
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        for j in range(i + 1, n):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue

            k = j + 1
            l = n - 1

            while k < l:
                total = nums[i] + nums[j] + nums[k] + nums[l]

                if total == target:
                    ans.append([nums[i], nums[j], nums[k], nums[l]])

                    k += 1
                    l -= 1

                    while k < l and nums[k] == nums[k - 1]:
                        k += 1

                    while k < l and nums[l] == nums[l + 1]:
                        l -= 1

                elif total > target:
                    l -= 1
                else:
                    k += 1

    return ans


if __name__ == "__main__":
    n = int(input())

    nums = list(map(int, input().split()))

    target = int(input())

    result = four_sum(nums, target)

    for quad in result:
        print(*quad)