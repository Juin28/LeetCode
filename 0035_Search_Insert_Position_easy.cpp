class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size() - 1;

        if (target <= nums[0])
            return 0;
        else if (target > nums[len])
            return len + 1;
        else if (target == nums[len])
            return len;

        int l = 0;
        int r = len;
        while (l < r)
        {
            int m = (l + r) >> 1;
            
            if ( (target > nums[l]) && (target < nums[l + 1]) )
                return l + 1;

            else if ( (target < nums[r]) && (target > nums[r - 1]) )
                return r;

            else if (target == nums[m])
                return m;
                
            else if (target > nums[m])
                l = m;

            else 
                r = m;
        }
        return 0;
    }
};
