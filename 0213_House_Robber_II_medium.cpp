class Solution {
public:
    int houseRobberOne(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int n : nums) {
            int newRob = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> nums1 (nums.begin(), nums.end() - 1);
        vector<int> nums2 (nums.begin() + 1, nums.end());

        return max(houseRobberOne(nums1), houseRobberOne(nums2));
    }
};
