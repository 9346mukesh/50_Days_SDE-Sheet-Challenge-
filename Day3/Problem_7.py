"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Rotate a matrix by 90 degrees
Problem Statement :- Given a 2D matrix, rotate it by 90 degrees clockwise.

(Time Complexity :- O(n^2) and Space Complexity :- O(1))

"""


def transposematrix(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(i+1,n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

def rotatematrix(matrix):
    
    transposematrix(matrix)
    
    for row in matrix:
        row.reverse()


if __name__ == "__main__":
    n = int(input().strip())
    matrix=[]
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    
    rotatematrix(matrix)
    
            
    for row in matrix:
        print(*row)