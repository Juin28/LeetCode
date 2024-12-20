class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int median = arr[(n - 1) / 2];

        vector<int> strongestK;
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < k; ++i) {
            int leftValue = abs(arr[left] - median);
            int rightValue = abs(arr[right] - median);

            if (leftValue > rightValue) {
                strongestK.push_back(arr[left]);
                ++left;
            } else {
                strongestK.push_back(arr[right]);
                --right;
            }
        }

        return strongestK;
    }
};

// Brute Force Solution
// class Solution {
// public:
//     vector<int> getStrongest(vector<int>& arr, int k) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         int median = arr[(n - 1) / 2];

//         priority_queue<vector<int>> maxHeap;

//         for (int i = 0; i < n; ++i) {
//             int newNum = abs(arr[i] - median);
//             maxHeap.push({newNum, i});
//         }

//         vector<int> strongestK;

//         for (int i = 0; i < k; ++i) {
//             int index = maxHeap.top()[1];
//             maxHeap.pop();
//             strongestK.push_back(arr[index]);
//         }

//         return strongestK;
//     }
// };
