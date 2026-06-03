/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Merge Two Sorted Arrays without ExtraSpace
Problem Statement :- Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

(Time Complexity :- O(m + n) and Space Complexity :- O(1))

"""
*/


#include<bits/stdc++.h>
using namespace std;


void mergetwosortedarrays(vector<int>& nums1, vector<int>& nums2, int m, int n){
    int left = m-1;
    int right = 0;

    while(left>=0 && right<n){
        if(nums2[right]<nums1[left]){
            swap(nums2[right],nums1[left]);
            left--;
            right++;
        }else{
            break;
        }
    }

    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

}

/*

"" Merged two sorted arrays using extra space ""
vector<int> mergetwosortedarrays(vector<int>& nums1, vector<int>& nums2, int m, 
int n){
    vector<int>ans;
    int first=0, second=0;
    while(first<m && second<n){
        if(nums1[first]<=nums2[second]){
            ans.push_back(nums1[first]);
            first++;
        }else{
            ans.push_back(nums2[second]);
            second++;
        }
    }
    
    while(first<m){
        ans.push_back(nums1[first]);
        first++;
    }
    
    while(second<n){
        ans.push_back(nums2[second]);
        second++;
    }
    
    return ans;
    
}
*/

int main(){
    int m, n;
    cin>>m>>n;
    vector<int>nums1(m);
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    
    vector<int>nums2(n);
    for(int i=0;i<n;i++){
        cin>>nums2[i];
    }
    
    // vector<int> merged = mergetwosortedarrays(nums1,nums2, m, n);

    mergetwosortedarrays(nums1, nums2, m, n);
    
    /*
    for(int i=0;i< merged.size();i++){
        cout<<merged[i]<<" ";
    }
    */

    cout << "Array 1: ";

    for (int x : nums1) {

        cout << x << " ";

    }

    cout << "\nArray 2: ";

    for (int x : nums2) {

        cout << x << " ";

    }
    return 0;
}