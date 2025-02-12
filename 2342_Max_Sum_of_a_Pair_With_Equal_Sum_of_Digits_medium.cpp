// More Optimal Approach
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> sumToLargest;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = 0;
            int tmpNum = num;

            while (tmpNum) {
                sumDigits += tmpNum % 10;
                tmpNum /= 10;
            }

            auto& largestPair = sumToLargest[sumDigits];
            if (num > largestPair.first) {
                largestPair.second = largestPair.first; 
                largestPair.first = num; 
            } else if (num > largestPair.second) {
                largestPair.second = num; 
            }
        }

        for (const auto& entry : sumToLargest) {
            if (entry.second.second != 0) { 
                int sum = entry.second.first + entry.second.second;
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

// class Solution {
// public:
//     int maximumSum(vector<int>& nums) {
//         unordered_map <int, vector<int> > sumToNumbers;
//         int maxSum = -1;

//         for (int num : nums) {
//             int sumDigits = 0;
//             int tmpNum = num;
//             while (tmpNum) {
//                 sumDigits += tmpNum % 10;
//                 tmpNum /= 10;
//             }

//             sumToNumbers[sumDigits].push_back(num);
//         }

//         for (auto& entry : sumToNumbers) {
//             vector<int>& numberVector = entry.second;
//             if (numberVector.size() <= 1) {
//                 continue;
//             }

//             auto largestNumIt = max_element(numberVector.begin(), numberVector.end());
//             int largestNum = *largestNumIt;
//             numberVector.erase(largestNumIt);
//             auto secondLargestNumIt = max_element(numberVector.begin(), numberVector.end());
//             int secondLargestNum = *secondLargestNumIt;

//             int sum = largestNum + secondLargestNum;
//             maxSum = max(maxSum, sum);
//         }

//         return maxSum;
//     }
// };

