class Solution {
public:
    int recursion(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            return target == sum;
        }

        return recursion(nums, target, index + 1, sum + nums[index]) + recursion(nums, target, index + 1, sum - nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums, target, 0, 0);
    }
}