"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the repeating and missing numbers
Problem Statement :- Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

(Time Complexity :- O(n) and Space Complexity :- O(1))

"""



def find_repeat_and_missing_number(nums):
    n = len(nums)

    Sn = n * (n + 1) // 2
    Sn2 = n * (n + 1) * (2 * n + 1) // 6

    S = sum(nums)
    S2 = sum(x * x for x in nums)

    value_1 = S - Sn          # x - y
    value_2 = S2 - Sn2        # x² - y²

    value_2 = value_2 // value_1  # x + y

    x = (value_1 + value_2) // 2  # repeating number
    y = x - value_1               # missing number

    return [x, y]




if __name__ == "__main__":
    n = int(input().strip())

    nums = list(map(int, input().split()))

    ans = find_repeat_and_missing_number(nums)


    print("Repeating Number:", ans[0])
    print("Missing Number:", ans[1])
