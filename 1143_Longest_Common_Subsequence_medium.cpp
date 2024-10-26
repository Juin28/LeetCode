class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        vector< vector<int> > dp (len1 + 1, vector<int> (len2 + 1, 0));

        // V1: Start from the end
        // for (int p1 = len1 - 1; p1 >= 0; --p1) {
        //     for (int p2 = len2 - 1; p2 >= 0; --p2) {
        //         if (text1[p1] == text2[p2]) {
        //             dp[p1][p2] = 1 + dp[p1 + 1][p2 + 1];
        //         } else {
        //             dp[p1][p2] = max(dp[p1 + 1][p2], dp[p1][p2 + 1]);
        //         }
        //     }
        // }

        // return dp[0][0];

        // V2: Start from the beginning
        // for (int p1 = 0; p1 < len1; ++p1) {
        //     for (int p2 = 0; p2 < len2; ++p2) {
        //         if (text1[p1] == text2[p2]) {
        //             if (p1 != 0 && p2 != 0) {
        //                 dp[p1][p2] = 1 + dp[p1 - 1][p2 - 1];
        //             } else {
        //                 dp[p1][p2] = 1;
        //             }
        //         } else {
        //             if (p1 != 0 && p2 != 0) {
        //                 dp[p1][p2] = max(dp[p1 - 1][p2], dp[p1][p2 - 1]);
        //             } else if (p1 == 0 && p2 != 0) {
        //                 dp[p1][p2] = dp[p1][p2 - 1];
        //             } else if (p1 != 0 && p2 == 0) {
        //                 dp[p1][p2] = dp[p1 - 1][p2];
        //             }
        //         }
        //     }
        // }

        // return dp[len1 - 1][len2 - 1];

        // V3: Start from the beginning (no need redundant checking)
        for (int p1 = 1; p1 <= len1; ++p1) {
            for (int p2 = 1; p2 <= len2; ++p2) {
                if (text1[p1 - 1] == text2[p2 - 1]) {
                    dp[p1][p2] = 1 + dp[p1 - 1][p2 - 1];
                } else {
                    dp[p1][p2] = max(dp[p1 - 1][p2], dp[p1][p2 - 1]);
                }
            }
        }

        return dp[len1][len2]; 
    }
};
