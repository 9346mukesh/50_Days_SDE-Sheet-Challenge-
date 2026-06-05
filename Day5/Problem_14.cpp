/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Majority Element that occurs more than N/2 times
Problem Statement :- Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
*/

// TC : O(2n) and SC : O(1)



#include<bits/stdc++.h>
using namespace std;

int majorityelement(vector<int>& nums, int n){
    int ele;
    int count=0;
    
    for(int i=0;i<n;i++){
        if(count==0){
            ele=nums[i];
            count+=1;
        }else if(nums[i]==ele){
            count+=1;
        }else{
            count-=1;
        }
    }
    // verify the element is majority element or not
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ele) {
            count++;
        }
    }
    
    if(count>n/2){
        return ele;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    cout<<"Majority Element of array is: "<<majorityelement(nums,n)<<"\n";
    
    return 0;
}