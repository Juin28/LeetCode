class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;

        vector<int> check (n + 1, 0);
        int max_trust = 0;
        int judge = 0;

        for (const auto& t : trust)
        {
            --check[t[0]];
            ++check[t[1]];
            
            if (check[t[1]] > max_trust)
            {
                max_trust = check[t[1]];
                judge = t[1];
            }
        }

        if (check[judge] == n-1)
            return judge;
            
        return -1;
    }
};