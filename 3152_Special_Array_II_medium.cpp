class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> numsIsSpecial(n - 1, false);
        vector<bool> queryIsSpecial(queries.size(), true);
        
        for (int i = 0; i < n - 1; ++i) {
            numsIsSpecial[i] = (nums[i] % 2 != nums[i + 1] % 2);
        }

        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + numsIsSpecial[i - 1];
        }

        for (int i = 0; i < queries.size(); ++i) {
            int from = queries[i][0];
            int to = queries[i][1];
            
            int specialCount = prefixSum[to] - prefixSum[from];
            if (specialCount != (to - from)) {
                queryIsSpecial[i] = false;
            }
        }
        
        return queryIsSpecial;
    }
};

