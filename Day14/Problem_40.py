def findMaxConsecutiveOnes(nums):
        maxlength=0
        length=0
        for i in range(len(nums)):
            if(nums[i]==1):
                length+=1
                maxlength=max(length,maxlength)
            else:
                length=0
        return maxlength


if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int, input().split()))

    result = findMaxConsecutiveOnes(nums)

    print(result)