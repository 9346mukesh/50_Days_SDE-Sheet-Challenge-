/*  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count Reverse Pairs
Problem Statement :-Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
(Time Complexity :- O(n^2) and Space Complexity :- O(1))

*/



#include<bits/stdc++.h>
using namespace std;

int countreversepair(vector<int>& nums, int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if(nums[i]> 2*nums[j]){
                count+=1;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    cout<<"No.of reverse pairs : "<<countreversepair(nums, n)<<"\n";
    
    return 0;
}
