// Optimal Solution O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        vector<int> last(10, -1);

        // Store the last position of each digit (0-9)
        for (int i = 0; i < numStr.size(); i++) {
            last[numStr[i] - '0'] = i;
        }

        // Try to find the first digit that can be swapped with a larger digit
        for (int i = 0; i < numStr.size(); i++) {
            for (int d = 9; d > numStr[i] - '0'; d--) {
                if (last[d] > i) {
                    // Swap the digits
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); 
                }
            }
        }

        return num;
    }
};

// O(n log n)
// class Solution {
// public:
//     int maximumSwap(int num) {
//         vector<int> nums;
//         int temp = num;
//         while(temp) {
//             int value = temp % 10;
//             temp /= 10;
//             nums.push_back(value);
//         }

//         vector<int> sortedNums (nums.begin(), nums.end());
//         sort(sortedNums.begin(), sortedNums.end());

//         unordered_map<int, int> getPosition;
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             getPosition[nums[i]] = i;
//         }

//         for (int i = nums.size() - 1; i >= 0; --i) {
//             if (nums[i] != sortedNums[i]) {
//                 int value1 = sortedNums[i];
//                 int value2 = nums[i];
//                 int position1 = getPosition[value1];
//                 nums[i] = value1;
//                 nums[position1] = value2;
//                 break;
//             }
//         }

//         int output = 0;
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             output += nums[i];
//             output *= 10;
//         }
//         output /= 10;

//         return output;
//     }
// };

