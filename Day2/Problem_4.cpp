/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Sort an array of 0s, 1s and 2s
Problem Statement :- Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array."""
*/

// TC : O(n) and SC : 0(1)

#include<bits/stdc++.h>
using namespace std;

void Sort_zeros_ones_twos(vector<int>& arr) { // Dutch National Flag Algorithm
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Sort_zeros_ones_twos(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}