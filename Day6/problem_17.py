""" Data Structure :- Dynamic Programming (Memoization)

Problem Name :- Unique Paths

Problem Statement :- Given two integers m and n, representing the number of rows and columns of a 2D grid.
Return the number of unique ways to go from the top-left cell to the bottom-right cell.

Movement is allowed only in two directions:
1. Right
2. Down

(Time Complexity :- O(m*n) and Space Complexity :- O(m*n))
"""


def count_paths(i, j, dp):

    # Base Case
    if i == 0 and j == 0:
        return 1

    # Out of Bounds
    if i < 0 or j < 0:
        return 0

    # Already Computed
    if dp[i][j] != -1:
        return dp[i][j]

    up = count_paths(i - 1, j, dp)
    left = count_paths(i, j - 1, dp)

    dp[i][j] = up + left

    return dp[i][j]


def unique_paths(m, n):

    dp = [[-1 for _ in range(n)] for _ in range(m)]

    return count_paths(m - 1, n - 1, dp)


if __name__ == "__main__":

    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))

    total_paths = unique_paths(m, n)

    print("Total Unique Paths:", total_paths)