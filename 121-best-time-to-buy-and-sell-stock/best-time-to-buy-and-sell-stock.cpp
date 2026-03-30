#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // minimum price till now
        int maxProfit = 0;        // maximum profit
        
        for (int i = 0; i < prices.size(); i++) {
            // update minimum price
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            // calculate profit
            int profit = prices[i] - minPrice;
            
            // update max profit
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};