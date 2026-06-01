
/*
 Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Next Permutation
Problem Statement :- Find the next lexicographically(Dictionary) greater permutation of a given array of integers
*/
// (Time Complexity :- O(n) and Space Complexity :- O(1))
#include<bits/stdc++.h>
using namespace std;

vector<int> next_permutation(vector<int>& arr){
    int n = arr.size();
    // return next_permutation(arr.begin(), arr.end()); Using C++ STL Function

    int index==-1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }

    // Edge Case( IF given Array is the Last Permutation Then  answer the First Permutation)
    if(index == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i =n-1;i>=0;i--){
        if(arr[index]<arr[i]){
            swap(arr[index], arr[i]);
            break;
        }
    }
    reverse(arr.begin()+index+1, arr.end());
    return arr;
}
    

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>ans(n) = next_permutation(arr);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}