// Optimal Solution
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                count += productCount[product] * 8;
                productCount[product]++;
            }
        }

        return count;
    }
};

// class Solution {
// public:
//     int tupleSameProduct(vector<int>& nums) {
//         int n = nums.size();

//         if (n < 4) {
//             return 0;
//         }

//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> productCount;
//         int count = 0;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int product = nums[i] * nums[j];
//                 productCount[product]++;
//             }
//         }

//         for (auto& entry : productCount) {
//             int numPairs = entry.second;
//             if (numPairs > 1) {
//                 cout << numPairs << endl;
//                 count += numPairs * (numPairs - 1) * 4;
//             }
//         }

//         return count;
//     }
// };
