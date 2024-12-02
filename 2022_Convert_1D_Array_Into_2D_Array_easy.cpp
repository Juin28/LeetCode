class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int originalSize = original.size();

        if ( (m * n) != originalSize ) {
            return {};
        }

        vector<vector<int>> newArray (m, vector<int> (n));

        for (int i = 0; i < originalSize; ++i) {
            int row = i / n;
            int col = i % n;

            newArray[row][col] = original[i];
        }

        return newArray;
    }
};

