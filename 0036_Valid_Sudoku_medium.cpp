class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector< unordered_map<char, bool> > row (9);
        vector< unordered_map<char, bool> > col (9);
        vector< unordered_map<char, bool> > square (9);

        for (int r = 0; r < 9; ++r) {
            int sq_r = (r/3)*3;
            for (int c = 0; c < 9; ++c) {
                char check = board[r][c];
                if (check == '.')
                    continue;
                
                if (row[r][check] || col[c][check] || square[sq_r + c/3][check])
                    return false;

                row[r][check] = true;
                col[c][check] = true;
                square[sq_r + c/3][check] = true;
            }
        }
        return true;
    }
};
