class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

        for (int i = 0; i <= l1; ++i) 
            dp[i][0] = i;

        for (int i = 0; i <= l2; ++i) 
            dp[0][i] = i;
        
        for(int p1 = 1; p1 <= l1; ++p1)
        {
            for(int p2 = 1; p2 <= l2; ++p2)
            {
                if (word1[p1-1] == word2[p2-1])
                    dp[p1][p2] = dp[p1-1][p2-1];
                else
                    dp[p1][p2] = min(dp[p1-1][p2-1], min(dp[p1-1][p2], dp[p1][p2-1])) + 1;
            }
        }
        return dp[l1][l2];
    }
};