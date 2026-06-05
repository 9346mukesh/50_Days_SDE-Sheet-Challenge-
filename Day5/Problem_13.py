"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Search in a sorted 2D matrix
Problem Statement :- ou have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. 
The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). 
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

(Time Complexity :- O(log(n*m)) and Space Complexity :- O(1))

"""
def findtarget(matrix, target, n, m):
    low, high = 0, n*m-1
    
    while low<=high:
        mid = low + (high - low) // 2
        row = mid//m
        col = mid%m
        
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] < target:
            low = mid+1
        else:
            high = mid-1
            
    return False

if __name__ == "__main__":
    n , m = map(int, input().split())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    
    target = int(input().strip())
    
    if(findtarget(matrix, target, n, m)):
        print(f"Target {target} is found\n")
    else:
        print(f"Target {target} is not found\n")