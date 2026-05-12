class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0 || n==1) return 0;
        
        int maxProfit = 0, maxStockPriceTillNow = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(prices[i] >= maxStockPriceTillNow) maxStockPriceTillNow = prices[i];
            else {
                int profit = maxStockPriceTillNow - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};