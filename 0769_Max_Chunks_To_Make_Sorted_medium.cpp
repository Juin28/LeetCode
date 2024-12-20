class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arrSize = arr.size();
        int largestSoFar = arr[0];
        int numChunks = 0;

        for (int i = 0; i < arrSize; ++i) {
            largestSoFar = max(largestSoFar, arr[i]);
            if (i == largestSoFar) {
                ++numChunks;
            }
        }

        return numChunks;
    }
};

