
/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Length of the longest subarray with zero Sum
Problem Statement :-Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
(Time Complexity :- O(n) and Space Complexity :- O(n))
*/



#include<bits/stdc++.h>
using namespace std;

int longestsubarray_withsumK(vector<int>& nums, int n, int k){
    int longest = 0;
    unordered_map<int,int> mpp;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += nums[i];

        if(sum == k){
            longest = max(longest, i + 1);
        }

        if(mpp.find(sum - k) != mpp.end()){
            longest = max(longest, i - mpp[sum - k]);
        }

        // Store first occurrence only
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }

    return longest;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int k;
    cin >> k;

    cout << longestsubarray_withsumK(nums, n, k);

    return 0;
}