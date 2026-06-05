/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Search in a sorted 2D matrix
Problem Statement :- ou have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively.
The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
*/

// TC : O(log(n*m)) and SC : O(1)



#include <bits/stdc++.h>
using namespace std;

bool findTarget(vector<vector<int>>& matrix, int target, int n, int m) {
    int low = 0, high = n * m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (findTarget(matrix, target, n, m)) {
        cout << "Target " << target << " is found" << endl;
    } else {
        cout << "Target " << target << " is not found" << endl;
    }

    return 0;
}