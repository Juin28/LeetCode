class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen (n + 1, false);

        for (int i : nums)
        {
            if (seen[i])
                return i;
            seen[i] = true;
        }

        return 0;
    }
};
