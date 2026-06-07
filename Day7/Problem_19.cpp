/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Two Sum :  Return All Unique pairs with given sum exists
Problem Statement :- Given an integer array nums of size n, return all unique pairs that sum up to the target value.

*/


#include<bits/stdc++.h>
using namespace std;


// Time Complexity: If the Problem is to find the Pair of Elemments that Gives the Target Sum,
// Then Sorting Array is fine but we change the original array
// T(C): O(log n) + O(n) = O(nlogn) and S(C): O(1)


/*

vector<int> twosum(vector<int>& nums, int n, int target){
    sort(nums.begin(),nums.end());
    vector<int>ele;
    int left = 0;
    int right = n-1;
    int sum = 0;
    while(left<right){
        sum = nums[left] + nums[right];
        if(sum == target){
            ele.push_back(nums[left]);
            ele.push_back(nums[right]);
            break;
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    return ele;
}

*/
// Time Complexity: O(n) and Space Complexity: O(n)
// we need the index of the elements so we need to store them in the map of SC : O(n) in worst case
vector<int> twosum(vector<int>& nums, int n, int target){
    unordered_map<int,int>mpp;
    int sum =0;
    
    for(int i=0;i<n;i++){
        int remaining = target - nums[i];
        if(mpp.find(remaining) != mpp.end()){
            return {mpp[remaining], i};
        }else{
            mpp[nums[i]] = i;
        }
    }
    
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int target;
    cin>> target;
    
    vector<int> ans = twosum(nums, n, target);
    
    /* if(ans.empty()){
        cout<<"Sum of any two elements in array is not equal target";
    }else{
        cout<<"sum of "<<ans[0]<<" and "<<ans[1]<<" is equal to the target";
    }
    */


    if(ans.empty()){
        cout<<"Sum of any two elements in array is not equal target";
    }else{
        cout<<"sum of "<<nums[ans[0]]<<" at index " << ans[0]<<" and "<<nums[ans[1]] <<" at index" <<ans[1]<<"is equal to target";
    }

    return 0;
}