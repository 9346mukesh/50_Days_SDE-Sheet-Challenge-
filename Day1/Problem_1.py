""" Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Set Matrix Zeroes
Problem Statement :- Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

(Time Complexity :- O(m*n) and Space Complexity :- O(m+n))

"""


def set_matrix_zeros(matrix):
    rows = len(matrix)
    columns = len(matrix[0])
    row_zero = [1] * rows
    column_zero = [1] * columns

    for i in range(rows):
        for j in range(columns):
            if matrix[i][j] == 0:
                row_zero[i] = 0
                column_zero[j] = 0

    for i in range(rows):
        for j in range(columns):
            if row_zero[i] == 0 or column_zero[j] == 0:
                matrix[i][j] = 0


if __name__ == "__main__":
    rows, cloumns = map(int, input().split())
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))
    
    set_matrix_zeros(matrix)

    for i in range(rows):
        for j in range(cloumns):
            print(matrix[i][j], end=" ")
        print()
    