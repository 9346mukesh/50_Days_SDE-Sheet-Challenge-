/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Kadane's Algorithm : Maximum Subarray Sum in an Array
Problem Statement :- "Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
""
*/

// TC : O(n) and SC : 0(1)



#include<bits/stdc++.h>
using namespace std;
/*
int subarraysum(vector<int>& nums){
    int n = nums.size();
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+= nums[j];
            if(sum>maxsum){
                maxsum=sum;
            }
        }
    }
    return maxsum;
}

*/

/*
int subarraysum(vector<int>& nums){
    int n = nums.size();
    int maxsum=INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum +=nums[i];
        
        if(sum> maxsum){
            maxsum=sum;
        }
        
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}

*/
int subarraysum(vector<int>& nums){
    int n = nums.size();
    int sum = nums[0];
    int maxsum = nums[0];
    
    for(int i=1;i<n;i++){
        sum = max(nums[i], sum+ nums[i]);
        maxsum = max(maxsum, sum);
    }
    
    return maxsum;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    
    int maxsubarray = subarraysum(nums);
    
    cout<< maxsubarray<<"\n";
    
    return 0;
}