// Optimal Approach
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; ++i) {
            if (i > farthest) {
                return false;
            }

            farthest = max(farthest, i + nums[i]);

            if (farthest >= n - 1) {
                return true;
            }
        }

        return false;
    }
};

// Brute Force Approach
// class Solution {
// public:
//     bool canJump(vector<int>& nums, int startIndex = 0) {
//         int n = nums.size();
//         int num = nums[startIndex];

//         if (startIndex == (n - 1) ) {
//             return true;
//         }

//         if (num == 0) {
//             return false;
//         }

//         bool result = false;

//         for (int i = 1; i <= num; ++i) {
//             int newStartIndex = startIndex + i;

//             if (newStartIndex >= n) {
//                 break;
//             }

//             result = result || canJump(nums, newStartIndex);
//         }

//         return result;
//     }
// };

