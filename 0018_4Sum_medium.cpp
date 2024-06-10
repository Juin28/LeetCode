class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> ans;
        int len = nums.size();

        if (len < 4)
            return ans;
        else if (len == 4)
        {
            long long sum = static_cast<long long>(nums[0]) + static_cast<long long>(nums[1]) + static_cast<long long>(nums[2]) + static_cast<long long>(nums[3]);
            if (sum == target)
                ans.push_back(nums);
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = len - 1; j > 2; j--)
            {
                if (j < (len - 1) && nums[j] == nums[j + 1])
                    continue;

                int l = i + 1;
                int r = j - 1;

                while (l < r)
                {
                    long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[l]) + static_cast<long long>(nums[r]);

                    if (sum == target)
                    {
                        ans.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});

                        while ( l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;
                    }

                    else if (sum > target) 
                        r--;
                    
                    else
                        l++;
                }
            }
        }
        return ans;    
    }
};