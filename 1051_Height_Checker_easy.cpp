class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int len = heights.size();
        if (len == 1)
            return 0;

        vector<int> ori = heights;
        int ans = 0;

        sort(heights.begin(), heights.end());

        for (int i = 0; i < len; i++)
        {
            ans += (ori[i] != heights[i]);
        }
        return ans;
    }
};