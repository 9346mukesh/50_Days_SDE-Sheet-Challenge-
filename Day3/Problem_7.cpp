/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Rotate a matrix by 90 degrees
Problem Statement :- Given a 2D matrix, rotate it by 90 degrees clockwise. */
*/

// TC : O(n^2) and SC : O(1)



#include<bits/stdc++.h>
using namespace std;

void transposematrix(vector<vector<int>>& matrix, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

void rotatematrix(vector<vector<int>>& matrix, int n){
    transposematrix(matrix,n);
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    rotatematrix(matrix,n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}