
/* Data Structure :- Strings(Sliding Window with Two pointers)
Problem Title :- Longest Substring Without Repeating Characters
Problem Statement :-Given A String  Return the length of the longest substring without repeating characters.
(Time Complexity :- O(n) and Space Complexity :- O(n))
*/


#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharacter(string s, int n) {
    int left = 0;
    int longest = 0;

    unordered_map<char, int> seen;

    for (int right = 0; right < n; right++) {

        if (seen.find(s[right]) != seen.end() &&
            seen[s[right]] >= left) {

            left = seen[s[right]] + 1;
        }

        seen[s[right]] = right;

        longest = max(longest, right - left + 1);
    }

    return longest;
}

int main() {
    string s;
    cin >> s;

    cout << longestSubstringWithoutRepeatingCharacter(s, s.length()) << "\n";

    return 0;
}