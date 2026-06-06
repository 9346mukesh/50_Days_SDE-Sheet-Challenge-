/* Data Structure :- Dynamic Programming (Memoization)
Problem Name :- Unique Paths
Problem Statement :- Given two integers m and n, representing the number of rows and columns of a 2D grid.
Return the number of unique ways to go from the top-left cell to the bottom-right cell.
Movement is allowed only in two directions: Right and Down.
*/

// TC : O(m*n) and SC : O(m*n) + O((m-1)+(n-1))

#include<bits/stdc++.h>
using namespace std;

int countpaths(int i, int j, vector<vector<int>>& dp){

    // Base Case
    if(i == 0 && j == 0){
        return 1;
    }

    // Out of Bounds
    if(i < 0 || j < 0){
        return 0;
    }

    // Check if already computed
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = countpaths(i-1, j, dp);
    int left = countpaths(i, j-1, dp);

    return dp[i][j] = up + left;
}

int uniquepaths(int m, int n){

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countpaths(m-1, n-1, dp);
}

int main(){

    int m, n;
    cin >> m >> n;

    int totalpaths = uniquepaths(m, n);

    cout << totalpaths;

    return 0;
}