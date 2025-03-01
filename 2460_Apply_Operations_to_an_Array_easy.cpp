class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> results;

        for (int i = 0; i < n - 1; ++i) {
            int& firstNum = nums[i];
            int& secondNum = nums[i + 1];

            if (firstNum == 0) {
                continue;
            }

            if (firstNum == secondNum) {
                results.push_back(firstNum * 2);
                secondNum = 0;
                ++i;
            } else {
                results.push_back(firstNum);
            }
        }

        int lastNum = nums[n - 1];
        if (lastNum != 0) {
            results.push_back(lastNum);
        }

        while (results.size() < n) {
            results.push_back(0);
        }

        return results;
        
    }
};

// 1 2 2 1 1 0
// 1 4 0 1 1 0
// 1 4 0 2 0 0
// 1 4 2 0 0 0 

