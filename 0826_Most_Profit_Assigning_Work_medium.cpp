// BRUTE FORCE SOLUTION

// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         int n = difficulty.size();
//         int m = worker.size();
//         vector< pair<int, int> > diff_and_prof;
//         int total_profit = 0;

//         for (int i = 0; i < n; i++)
//         {
//             diff_and_prof.push_back(make_pair(profit[i], difficulty[i]));
//         }

//         sort(diff_and_prof.begin(), diff_and_prof.end());
//         sort(worker.begin(), worker.end());

//         for (int i = 0; i < m; i++)
//         {
//             int idx = n - 1;
//             int ability = worker[i];
//             while (idx >= 0 && ability < diff_and_prof[idx].second)
//             {
//                 idx--;
//             }
//             total_profit += (idx >= 0) ? diff_and_prof[idx].first : 0;
//         }
//         return total_profit;
//     }
// };

// OPTIMAL SOLUTION

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfitUpToDifficulty (maxDifficulty + 1, 0);

        for (int i = 0; i < difficulty.size(); ++i) 
            maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);

        for (int i = 1; i <= maxDifficulty; ++i) 
            maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);

        int totalProfit = 0;
        for (int ability : worker) 
        {
            if (ability > maxDifficulty) 
                totalProfit += maxProfitUpToDifficulty[maxDifficulty];
            else 
                totalProfit += maxProfitUpToDifficulty[ability];
            
        }

        return totalProfit;
    }
};
