class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int largest_sum = nums[0];

        for(int i = 1; i < nums.size(); ++i) 
        {
            current_sum = max(current_sum + nums[i], nums[i]);
            largest_sum = max(largest_sum, current_sum);
        }

        return largest_sum;
    }
};