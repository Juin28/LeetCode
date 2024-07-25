class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        if (target < nums[0] || target > nums[r])
            return -1;

        while (l <= r) 
        {
            int m = (l + r) >> 1;
            int num = nums[m];
            if (target == num)
                return m;
            else if (target > num)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};
