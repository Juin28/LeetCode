#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0;

        for (int i = 1; i < len; i++)
        {
            if (nums[i] <= nums[i-1])
            {
                int diff = nums[i-1] - nums[i] + 1;
                nums[i] += diff;
                ans += diff;
            }
        }
        return ans;
    }
};