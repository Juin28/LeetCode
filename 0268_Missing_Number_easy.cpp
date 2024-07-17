// O(n) -- optimize solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        int n = nums.size();

        for (int i = 1; i <= n; ++i)
            missing ^= i;
        
        for (int& i : nums)
            missing ^= i;
        
        return missing;
    }
};


// O(n)
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int missing = 0;
//         int n = nums.size();
//         vector<bool> seen (n + 1, false);

//         for (int& i : nums)
//         {
//             seen[i] = true;
//             while (seen[missing])
//                 ++missing;
//         }

//         return missing;
//     }
// };