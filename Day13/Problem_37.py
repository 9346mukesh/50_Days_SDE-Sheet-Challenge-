def threesum(nums, n, target):
    nums.sort()
    triplets = []

    for i in range(n - 1):

        if i > 0 and nums[i] == nums[i - 1]:
            continue

        j = i + 1
        k = n - 1

        while j < k:

            curr_sum = nums[i] + nums[j] + nums[k]

            if curr_sum == target:

                triplets.append([nums[i], nums[j], nums[k]])

                j += 1
                k -= 1

                while j < k and nums[j] == nums[j - 1]:
                    j += 1

                while j < k and nums[k] == nums[k + 1]:
                    k -= 1

            elif curr_sum < target:
                j += 1
            else:
                k -= 1

    return triplets


if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int, input().split()))
    target = int(input().strip())

    triplets = threesum(nums, n, target)

    if not triplets:
        print("No Triplets Found")
    else:
        for triple in triplets:
            print(*triple)