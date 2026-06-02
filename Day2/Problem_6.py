""" Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Stock Buy And Sell
Problem Statement :- "You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


(Time Complexity :- O(n) and Space Complexity :- O(1))

"""



def stockbuyandsell(stocks):
    n = len(stocks)
    maxprofit = 0;
    minprice = float('inf')
    
    for i in range(n):
        minprice = min(minprice, stocks[i])  # Track the minimum stock price seen so far.
        maxprofit = max(maxprofit, stocks[i]- minprice) # For each day, calculate the profit if you sell on that day and store Maxprofit
    
    return maxprofit



if __name__ == "__main__":
    days=int(input().strip())
    stocks=list(map(int, input().split()))
    
    print(stockbuyandsell(stocks))
    
    