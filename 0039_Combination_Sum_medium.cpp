class Solution {
public:
    void getAllCombination(vector<int>& candidates, int target, vector<vector<int>>& results, vector<int>& currentCombination, int currentIndex) {
        int n = candidates.size();

        for (int i = currentIndex; i < n; ++i) {
            int newTarget = target - candidates[i];
            if (newTarget < 0) {
                break;
            }

            vector<int> newCombination = currentCombination;
            newCombination.push_back(candidates[i]);
            if (newTarget == 0) {
                results.push_back(newCombination);
                break;
            } 
            getAllCombination(candidates, newTarget, results, newCombination, i);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target) {
            return {};
        }

        vector<vector<int>> results;
        vector<int> currentCombination = {};

        getAllCombination(candidates, target, results, currentCombination, 0);
        return results;
    }
};

