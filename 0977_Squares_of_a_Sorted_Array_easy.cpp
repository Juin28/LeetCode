class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int l = n - 1;
        int r = -1;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] >= 0)
            {
                r = i;
                l = (i - 1 >= 0) ? i - 1 : -1;
                break;
            }
        }

        while (r >= 0 && l >= 0 && r < n)
        {
            if (abs(nums[r]) >= abs(nums[l]))
            {
                ans.push_back(pow(nums[l], 2));
                l--;
            }
            else 
            {
                ans.push_back(pow(nums[r], 2));
                r++;
            }
        }

        while (l >= 0)
        {
            ans.push_back(pow(nums[l], 2));
            l--;
        }

        while (r >= 0 && r < n)
        {
            ans.push_back(pow(nums[r], 2));
            r++;
        }
        
        return ans;
    }
};