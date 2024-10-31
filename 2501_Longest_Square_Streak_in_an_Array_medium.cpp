class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> squareStreak;
        int longestCount = -1;
        
        sort(nums.begin(), nums.end());

        for (int num : nums) {
            int squareRoot = sqrt(num);

            if (squareRoot*squareRoot == num && squareStreak.find(squareRoot) != squareStreak.end()) {
                squareStreak[num] = squareStreak[squareRoot] + 1;
                longestCount = max(longestCount, squareStreak[num]);
            } else {
                squareStreak[num] = 1;
            }
        }

        return longestCount;
    }
};
