/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- 4 Sum | Find Quads that add up to a target value
Problem Statement :- Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
Note: a, b, c and d are also distinct and lies between 0 to n-1 (both inclusive).

(Time Complexity :- O(n log n) + O(n^3)and Space Complexity :- O(1))
*/



#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>foursum(vector<int>& nums, int n, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]== nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]== nums[j-1]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            
            while(k<l){
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l] == nums[l+1]){
                        l--;
                    }
                }else if(sum>target){
                    l--;
                }else{
                    k++;
                }
            }
        }
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
    
    int target;
    cin>> target;
    
    vector<vector<int>> ans = foursum(nums, n, target);
    
    for(int i =0;i<ans.size();i++){
        for(int j =0;j<ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
        cout<<"\n";
    }
    
    return 0;
}
