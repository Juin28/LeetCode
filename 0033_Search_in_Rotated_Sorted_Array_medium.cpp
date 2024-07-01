class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int m = (l + r) >> 1;

            if (nums[m] == target)
                return m;
            
            if (nums[m] >= nums[l])     // left half is sorted
            { 

                if (nums[l] <= target && target < nums[m]) 
                    r = m - 1;

                else 
                    l = m + 1;
                
            } 
            else                        // right half is sorted
            {   
                if (nums[m] < target && target <= nums[r]) 
                    l = m + 1;

                else 
                    r = m - 1;
            }

        }

        return -1;
    }
};