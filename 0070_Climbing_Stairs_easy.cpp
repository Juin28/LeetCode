class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        
        int dp [46] {0};
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }

        return dp[n-1];
    }
};