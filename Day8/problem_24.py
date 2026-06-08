
"""  Data Structure :- Strings(Sliding Window with Two pointers)
Problem Title :- Longest Substring Without Repeating Characters
Problem Statement :-Given A String  Return the length of the longest substring without repeating characters.
(Time Complexity :- O(n) and Space Complexity :- O(n))

"""


def longestsubstring_withoutrepeating_character(s, n):

    left = 0
    right = 0
    longest = 0
    last_seen = {}
    while right < n :
        ch = s[right]
        if ch in last_seen and last_seen[ch] >= left:
            left = last_seen[ch] + 1
        last_seen[ch] = right
        longest = max(longest, right - left + 1)
        right += 1
    return longest

""" def longestsubstring_withoutrepeating_character(s, n):
    longest = 0

    for i in range(n):
        hashset = [0] * 256

        for j in range(i, n):
            if hashset[ord(s[j])] == 1:
                break

            hashset[ord(s[j])] = 1
            longest = max(longest, j - i + 1)

    return longest

"""

if __name__ == "__main__":
    n = int(input().strip());
    s = input().strip()
    
    ans = longestsubstring_withoutrepeating_character(s, n)
    
    print(ans)