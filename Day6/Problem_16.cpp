/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the Majority Element that occurs more than N/3 times
Problem Statement :- Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/3 times in the array. The array is guaranteed to have a majority element.
*/

// TC : O(2n) and SC : O(1)


#include<bits/stdc++.h>
using namespace std;

vector<int> findmajorityelements(vector<int>& nums, int n){
    int ele1 =INT_MIN, ele2=INT_MIN; // intilaize the element to zero causes problem when the starting element is zero so we can initialize it to any value which is not present in the array
    int count1 = 0;
    int count2 = 0;
    vector<int>ans;
    
    for(int i=0;i<n;i++){
        if(count1==0 && nums[i] != ele2){
            ele1=nums[i];
            count1 +=1;
        }else if(count2 ==0 && nums[i] != ele1){
            ele2=nums[i];
            count2 +=1;
        }else if(nums[i]==ele1){
            count1 +=1;
        }else if(nums[i]==ele2){
            count2 +=1;
        }else{
            count2 -=1;
            count1 -=1;
        }
    }
    
    count1=0;
    count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele1){
            count1+=1;
        }else if(nums[i] == ele2){
            count2+=1;
        }
    }
    if(count1>n/3){
        ans.push_back(ele1);
    }
    if(count2>n/3){
        ans.push_back(ele2);
    }
    return ans;
}



int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    vector<int> majority = findmajorityelements(nums, n);
    
    if(majority.empty()){
        cout<<"No majority elements";
    }else{
        for(int i =0;i<majority.size();i++){
            cout<<majority[i]<<" ";
        }
    }
    return 0;
}