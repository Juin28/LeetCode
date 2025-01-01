// Optimized Solution - DP
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n - 1];
        vector<int> dp (lastDay + 1, 0);

        int curr = 1;
        for (int i = 0; i < n; ++i, ++curr) {
            int day = days[i];

            while (curr < day) {
                dp[curr] = dp[curr - 1];
                ++curr;
            }

            int costOneDay = dp[day - 1] + costs[0];
            int costSevenDays = dp[max(0, day - 7)] + costs[1];
            int costThirtyDays = dp[max(0, day - 30)] + costs[2];

            dp[day] = min(costOneDay, min(costSevenDays, costThirtyDays));
        }

        return dp[lastDay];
    }
};

// Brute Force Solution - Recursion
// class Solution {
// public:
//     int getMinCost(vector<int>& days, vector<int>& costs, int validUntil, int index, int cost) {
//         int n = days.size();

//         // Find the first invalid day
//         while (index < n && validUntil > days[index]) {
//             ++index;
//         }

//         if (index == n) {
//             return cost;
//         }
        
//         // Make the first invalid day becomes valid
//         int oneDayCost = getMinCost(days, costs, max(validUntil, days[index]) + 1, index + 1, cost + costs[0]);
//         int sevenDaysCost = getMinCost(days, costs, max(validUntil, days[index]) + 7, index + 1, cost + costs[1]);
//         int thirtyDaysCost = getMinCost(days, costs, max(validUntil, days[index]) + 30, index + 1, cost + costs[2]);


//         return min(oneDayCost, min(sevenDaysCost, thirtyDaysCost));
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return getMinCost(days, costs, 0, 0, 0);
//     }
// };

