class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;
        int minPrice = prices[0];
        int maxPrice = -1;
        
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i - 1]) {
                if (maxPrice != -1) {
                    profit += (maxPrice - minPrice);
                }

                minPrice = prices[i];
                maxPrice = -1;
            } else {
                maxPrice = max(maxPrice, prices[i]);
                minPrice = min(minPrice, prices[i]);
            }
        }
        
        if (maxPrice != -1) {
            profit += (maxPrice - minPrice);
        }

        return profit;
    }
};
