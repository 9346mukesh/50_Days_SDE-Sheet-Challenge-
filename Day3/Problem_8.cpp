/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Merge Overlapping Intervals
Problem Statement :- Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

// TC : O(n log n) and SC : O(1)


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals, int n) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || ans.back()[1] < intervals[i][0]) {
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> merged = mergeIntervals(intervals, n);

    for (int i = 0; i < merged.size(); i++) {
        cout << merged[i][0] << " " << merged[i][1] << endl;
    }

    return 0;
}