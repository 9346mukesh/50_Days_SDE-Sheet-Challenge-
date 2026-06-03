
"""  Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Merge Overlapping Intervals
Problem Statement :- Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

(Time Complexity :- O(n log n) and Space Complexity :- O(1))

"""

def merge_intervals(intervals):
    intervals.sort()  # Sort by start time

    merged = []

    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])

    return merged

if __name__ == "__main__":
    n = int(input("Enter number of intervals: "))
    intervals = []
    for _ in range(n):
        start, end = map(int, input().split())
        intervals.append([start, end])
    
    merged = merge_intervals(intervals)
    for interval in merged:
        print(interval[0], interval[1])