class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minimum (m, 100001);
        vector<int> maximum (n, 0);
        vector<int> lucky;

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int temp = matrix[r][c];
                minimum[r] = min(minimum[r], temp);
                maximum[c] = max(maximum[c], temp);
            }
        }

        for (int& small : minimum)
        {
            for(int& big : maximum)
            {
                if (small == big)
                    lucky.push_back(small);
            }
        }

        return lucky;
    }
};