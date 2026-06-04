/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count inversions in an array
Problem Statement :- Given an array of N integers, count the inversion of the array.

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
*/

// TC : O(n^2) and SC : O(1)


#include<bits/stdc++.h>
using namespace std;

int countinversion(vector<int>& nums, int n){
    int cnt = 0;

    for(int i=0;i<n-1;i++){
        for(int j= i+1;j<n;j++){
            if(nums[j]<nums[i]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<countinversion(nums,n);

    return 0;
}