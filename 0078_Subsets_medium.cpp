class Solution {
public:
    void getSubsets(vector<vector<int>>& totalSubsets, vector<int>& nums, vector<int>& currentSubset, int currentIndex) {

        totalSubsets.push_back(currentSubset);

        for (int i = currentIndex; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);  
            getSubsets(totalSubsets, nums, currentSubset, i + 1);
            currentSubset.pop_back(); 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> totalSubsets;

        vector<int> currentSubset;
        getSubsets(totalSubsets, nums, currentSubset, 0);

        return totalSubsets;
    }
};

