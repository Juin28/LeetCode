class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int total = nums[0];

        for(int i = 1; i < nums.size(); ++i) 
        {
            total = total ^ nums[i];
        }

        return total;
    }
};