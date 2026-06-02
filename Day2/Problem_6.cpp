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