class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        int total = (static_cast<double>(1 + len)/2)*len;

        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
            {
                ans.push_back(idx + 1);
                continue;
            }
            nums[idx] = -nums[idx];
            total -= abs(nums[i]);
        }
        ans.push_back(total);
        return ans;
    }
};