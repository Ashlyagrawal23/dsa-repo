class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minBuy = prices[0];
     int maxProfit = 0;
     for(int i =0; i <prices.size(); i++){
        minBuy = min(prices[i], minBuy);
        maxProfit = max(maxProfit, prices[i] - minBuy);

     }
     return maxProfit;
        
    }
};