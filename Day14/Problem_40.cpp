#include<bits/stdc++.h>
using namespace std;

int maximumones(vector<int>& nums, int n){
    int left=0;
    int right =0;
    int maxi=0;
    while(right<n){
        if(nums[right]==1){
            right++;
        }else{
            maxi = max(maxi, right-left+1);
            right++;
            left=right;
        }
    }
    return maxi;
}
/*
int maximumones(vector<int>& nums, int n){
    int count =0;
    int maxi =0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            count++;
            maxi = max(maxi, count);
        }else{
            count =0;
        }
    }
    return maxi;
*/ 
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int maxones = maximumones(nums, n);
    cout<< maxones<<"\n";
    return 0;
}