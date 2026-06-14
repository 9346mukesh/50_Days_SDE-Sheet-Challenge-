#include<bits/stdc++.h>
using namespace std;


int removeduplicatesfromsortedarray(vector<int>& nums, int n){
    int i=0;
    for(int j= 1;j<n;j++){
        if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i = i+1;
        }
    }
    return i+1;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int ans = removeduplicatesfromsortedarray(nums, n);
    
    for(int i=0;i<ans;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}