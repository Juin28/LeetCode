// Dynamic Programming Approach
class Solution {
public:
    int findMaxProfit(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;

        if (buy == 1) {
            int profitBuyNow = -prices[index] + findMaxProfit(index + 1, 0, prices, dp);
            int profitBuyLater = findMaxProfit(index + 1, 1, prices, dp);
            profit = max(profitBuyNow, profitBuyLater);
        } else {
            int profitSellNow = prices[index] + findMaxProfit(index + 2, 1, prices, dp);
            int profitSellLater = findMaxProfit(index + 1, 0, prices, dp);
            profit = max(profitSellNow, profitSellLater);
        }

        dp[index][buy] = profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int> (2, -1));

        return findMaxProfit(0, 1, prices, dp);
    }
};


// Brute Force Approach
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int lowestPrice = -1) {
//         int n = prices.size();

//         if (n < 2) {
//             return 0;
//         }

//         int profit = 0;
//         int minPrice = (lowestPrice == -1) ? prices[0] : lowestPrice;
//         int maxPrice = -1;

//         for (int i = 1; i < n; ++i) {
//             if (prices[i] > minPrice) {
//                 int profitSoldNow = prices[i] - minPrice;
//                 int profitSoldLater = 0;

//                 if (i < n - 1) {
//                     vector<int> pricesSoldLater (prices.begin() + i, prices.end());
//                     profitSoldLater = maxProfit(pricesSoldLater, minPrice);

//                     if (i < n - 2) {
//                         vector<int> pricesSoldNow (prices.begin() + i + 2, prices.end());
//                         profitSoldNow += maxProfit(pricesSoldNow);
//                     }
//                 }

//                 return max(profitSoldNow, profitSoldLater);

//             } else {
//                 maxPrice = max(maxPrice, prices[i]);
//                 minPrice = min(minPrice, prices[i]);
//             }
//         }

//         return profit;
//     }
// };



