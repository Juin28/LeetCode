class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // if (nums.size() == 1)
        //     return;
        // else if (nums.size() == 2)
        // {
        //     int temp = nums[0];
        //     nums[0] = nums[1];
        //     nums[1] = temp;
        //     return;
        // }

        int len = nums.size();
        int first = -1;

        for (int i = len - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                first = i;
                break;
            }
        }     

        if (first == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = len - 1; i > first; i--)
        {
            if (nums[i] > nums[first])
            {
                swap(nums[i], nums[first]);
                break;
            }
        }

        reverse(nums.begin() + first + 1, nums.end());
    }
};