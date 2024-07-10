class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hasDuplicate;
        for(const int& i: nums)
        {
            if (hasDuplicate[i])
                return true;
            hasDuplicate[i] = true;
        }
        return false;
    }
};