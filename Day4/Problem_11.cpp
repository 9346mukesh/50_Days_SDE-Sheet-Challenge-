/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Find the repeating and missing numbers
Problem Statement :- Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.
*/

// TC : O(n) and SC : O(1)





#include<bits/stdc++.h>
using namespace std;

vector<int> findrepeatandmissingnumber(vector<int>& nums, int n){
    long long Sn = (n*(n+1))/2;
    long long Sn2 = (n*(n+1)*(2*₹n+1))/6;

    long long S=0, long long S2=0;
    for(int i=0;i<n;i++){
        S+=nums[i];
        S2+=nums[i]*nums[i];
    }
    long value_1 = S-Sn;
    long value_2 = S2 - Sn2;

    value_2 = value_2/value_1;

    long long x = (value_1 + value_2)/2;
    long long y = x - value_1;
    return {(int)x, (int)y};
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> ans = findrepeatandmissingnumbers(nums,n);

    cout<<"Repeating Number: "<<ans[0]<<"\n";
    cout<<"Missing Number: "<<ans[1]<<"\n";


    return 0;
}