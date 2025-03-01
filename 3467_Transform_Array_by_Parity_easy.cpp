class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int oddCount = 0;
        int evenCount = 0;
        vector<int> results;

        for (int& num : nums) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        for (int i = 0; i < evenCount; ++i) {
            results.push_back(0);
        }
        for (int i = 0; i < oddCount; ++i) {
            results.push_back(1);
        }

        return results;
    }
};
