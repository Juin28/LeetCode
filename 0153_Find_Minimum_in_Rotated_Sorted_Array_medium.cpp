class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int smallest = nums[0];

        while (l <= r)
        {
            if (nums[l] <= nums[r])
            {
                smallest = min(smallest, nums[l]);
                return smallest;
            }
            
            int m = (l + r) >> 1;
            smallest = min(smallest, nums[m]);
            if (nums[m] >= nums[l])
                l = m + 1;
            else
                r = m - 1;  
        }

        return smallest;
    }
};
