
/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Count the number of subarrays with given xor K
Problem Statement :-  Given an array of integers and an integer K, find the total number of subarrays having XOR of their elements as K.
(Time Complexity :- O(n^2) and Space Complexity :- O(1))
(Brute Force)
*/



#include<bits/stdc++.h>
using namespace std;

int count_subarraywithXORK(vector<int>& nums, int n, int k){
    int count =0;
    for(int i=0;i<n;i++){
        int XOR =0;
        for(int j=i;j<n;j++){
            XOR^=nums[j];
            if(XOR == k){
                count++;
            }
        }
    }
    return count;

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int k;
    cin>>k;
    
    int ans = count_subarraywithXORK(nums, n, k);
    
    cout<<ans<<"\n";
    
    return 0;
}