/* Data Structure :- Arrays(1-D & 2-D Arrays)
Problem Name :- Stock Buy And Sell
Problem Statement :- "You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


(Time Complexity :- O(n) and Space Complexity :- O(1))

*/



#include<bits/stdc++.h>
using namespace std;

int stockbuySell(vector<int>& stocks){
    int n = stocks.size();
    int min_price = INT_MAX;
    int max_profit = 0;
    
    for(int i=0; i<n;i++){
        min_price = min(min_price, stocks[i]);
        max_profit = max(max_profit, stocks[i]- min_price);
    }
    
    return max_profit;
}

int main(){
    int days;
    cin>> days;
    vector<int> stocks(days);
    for(int i=0;i<days;i++){
        cin>> stocks[i];
    }
    
    cout<<stockbuySell(stocks)<<"\n";
    
    
    return 0;
}