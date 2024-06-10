class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return ans;

        sort(nums.begin(), nums.end());
        int len = nums.size();
        ans = nums[0] + nums[1] + nums[2];
        int max = nums[len - 1] + nums[len - 2] + nums[len - 3];

        if (ans >= target)
            return ans;
        else if (max <= target)
            return max;

        for (int i = 0; i < len - 2; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int j = i + 1;
            int k = len - 1;

            while (j < k) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;

                else if ( abs(sum - target) < abs(ans - target) ) 
                    ans = sum;
                
                if (sum < target) 
                {    
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    j++;
                }
                else 
                {
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }
        }
        return ans;
    }
};
