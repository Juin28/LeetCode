// O(n log n) -- 51ms
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        int len = 1;

        if (n == 0) 
            return 0;

        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] == nums[i - 1])
                continue;

            if (nums[i] - nums[i - 1] == 1) 
                ++len; 

            else 
            {
                max_len = max(max_len, len); 
                len = 1;
            }
        }

        max_len = max(max_len, len);
        return max_len;
    }
};

//  O(n) -- 955ms
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) 
//             return 0;

//         unordered_set<int> num_set(nums.begin(), nums.end());
//         int max_len = 0;

//         for (int num : nums) 
//         {
//             if (!num_set.count(num - 1)) 
//             {
//                 int current_num = num;
//                 int len = 1;

//                 while (num_set.count(current_num + 1)) 
//                 {
//                     ++current_num;
//                     ++len;
//                 }

//                 max_len = max(max_len, len);
//             }
//         }

//         return max_len;
//     }
// };