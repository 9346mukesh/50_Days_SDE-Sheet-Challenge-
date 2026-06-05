"""  Topic :- Maths
Problem Name :- Implement Pow(x,n) | X raised to the power N
Problem Statement :- Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

(Time Complexity :- O(log n) and Space Complexity :- O(1))

"""


"""def myPow(x, n):
    ans = 1
    for _ in range(n):
        ans *= x
    return ans

"""


def myPow(x, n):
    ans = 1.0
    power = abs(n)

    while power > 0:
        if power % 2 == 1:
            ans *= x
            power -= 1
        else:
            x *= x
            power //= 2

    if n < 0:
        return 1 / ans
    
    return ans


if __name__ == "__main__":
    x = float(input())
    n = int(input())

    print(myPow(x, n))