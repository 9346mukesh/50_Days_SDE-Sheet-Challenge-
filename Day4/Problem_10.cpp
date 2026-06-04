/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Duplicate Number
Problem Statement :- Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.
*/

// TC : O(n) and SC : O(1)





#include<bits/stdc++.h>
using namespace std;

/* int findduplicatednumber(vector<int>& nums, int n){
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i]) == mpp.end()){
            mpp[nums[i]]+=1;
        }else{
            return nums[i];
        }
    }
    
    return -1;
}

*/
/*
int findduplicatednumber(vector<int>& nums, int n){
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]){
            return nums[i];
        }
    }
    return -1;
}
*/

int findduplicatednumber(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    slow = nums[0];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    cout<<"Duplicated Number is: "<<findduplicatednumber(nums)<<"\n";
    return 0;
}