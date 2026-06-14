def removeduplicatesfromsortedarray(nums, n):
    i = 0

    for j in range(1, n):
        if nums[i] != nums[j]:
            nums[i + 1] = nums[j]
            i = i + 1

    return i + 1


if __name__ == "__main__":
    n = int(input())

    nums = list(map(int, input().split()))

    ans = removeduplicatesfromsortedarray(nums, n)

    for i in range(ans):
        print(nums[i], end=" ")