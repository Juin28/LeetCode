class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int row = bottom;

        if (matrix[bottom][0] > target)
        {
            while (top <= bottom) 
            {
                int row_mid = (top + bottom) >> 1;
                int num = matrix[row_mid][0];
                if (num == target)
                    return true;
                else if (num < target)
                {
                    if (matrix[row_mid+1][0] == target)
                    {
                        row = row_mid + 1;
                        break; 
                    }
                    else if (matrix[row_mid+1][0] > target)
                    {
                        row = row_mid;
                        break; 
                    }
                    else
                    {
                        top = row_mid + 2;
                    }
                }
                else    // num > target
                {
                    bottom = row_mid - 1;
                }
            }
        }

        while (left <= right)
        {
            int col_mid = (left + right) >> 1;
            int num = matrix[row][col_mid];
            if (num == target)
                return true;
            else if (num < target)
                left = col_mid + 1;
            else
                right = col_mid - 1;
        }

        return false;
    }
};
