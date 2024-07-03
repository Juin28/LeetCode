class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_price = prices[0];
        
        for (int i = 1; i < n; ++i) 
        {
            int price = prices[i];
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        
        return max_profit;
    }
};