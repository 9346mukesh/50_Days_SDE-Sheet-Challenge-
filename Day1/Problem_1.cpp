/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Set Matrix Zeroes
Problem Statement :- Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix."""
*/

#include<bits/stdc++.h>
using namespace std;

// Fuction Block(Time Complexity :- O(m*n) and Space Complexity :- O(m+n))


void setmatrixzeroes(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<int> row_zeros(rows, 1); //  Uses O(m) Space
    vector<int> column_zeros(columns, 1); // Uses O(n) Space

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j] == 0){
                row_zeros[i] = 0;
                column_zeros[j] = 0;
            }
        }
    }
    // Setting the rows and columns to zeroes
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(row_zeros[i] == 0 || column_zeros[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

}


int main(){

    // Inputs Block
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> matrix(rows, vector<int> (columns));
    for(int i=0; i<rows; i++){
        for(int j=0;j<columns; j++){
            cin>>matrix[i][j];
        }
    }

   setmatrixzeroes(matrix); Function Call

    // Output Block
    for(int i=0; i<rows; i++){
        for(int j=0;j<columns; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}