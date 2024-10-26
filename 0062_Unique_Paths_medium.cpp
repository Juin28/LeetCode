class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > dp (m, vector<int> (n, 0));

        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (c == 0) {
                    dp[r][c] = dp[r - 1][c];
                } else {
                    dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
