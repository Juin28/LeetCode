// Memoization
class Solution {
public:
    int DFS(int curR, int curC, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (memo[curR][curC] != -1) {
            return memo[curR][curC];
        }

        int ROW = grid.size();
        int COL = grid[0].size();
        int maxCount = 0; 

        vector<pair<int, int>> validMoves = {{-1, 1}, {0, 1}, {1, 1}};
        for (pair<int, int>& move : validMoves) {
            int newR = curR + move.first;
            int newC = curC + move.second;

            if (newR >= 0 && newR < ROW && newC >= 0 && newC < COL && grid[newR][newC] > grid[curR][curC]) {
                maxCount = max(maxCount, 1 + DFS(newR, newC, grid, memo));
            }
        }

        // Store the result before returning
        memo[curR][curC] = maxCount;
        return maxCount;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<int>> memo(ROW, vector<int>(COL, -1));
        int maxCount = 0;

        for (int r = 0; r < ROW; ++r) {
            maxCount = max(maxCount, DFS(r, 0, grid, memo));
        }

        return maxCount;
    }
};

// Brute Force Solution
// class Solution {
// public:
//     void DFS(int curR, int curC, vector<vector<int>>& grid, int& count) {
//         int ROW = grid.size();
//         int COL = grid[0].size();

//         count++;

//         if (curC == COL - 1) {
//             return;
//         }

//         int tmpCount = count;

//         vector<pair<int, int> > validMoves = {{-1, 1}, {0, 1}, {1, 1}};
//         for(pair<int, int>& move : validMoves) {
//             int curCount = tmpCount;
//             int newR = curR + move.first;
//             int newC = curC + move.second;
//             if (newR >= 0 && newR < ROW && newC >= 0 && newC < COL && grid[newR][newC] > grid[curR][curC]) {
//                 DFS(newR, newC, grid, curCount);
//             }

//             count = max(count, curCount);

//             if (count == COL - 1) {
//                 return;
//             }
//         }
//     }

//     // bool isValidMove(int r, int c, int ROW, int COL) {
//     //     return (r >= 0 && r < ROW && c >= 0 && c < COL);
//     // }

//     int maxMoves(vector<vector<int>>& grid) {
//         int ROW = grid.size();
//         int COL = grid[0].size();
//         int maxCount = 0;

//         for (int r = 0; r < ROW; ++r) {
//             int count = 0;
            
//             vector<pair<int, int> > validMoves = {{-1, 1}, {0, 1}, {1, 1}};
//             for(pair<int, int>& move : validMoves) {
//                 count = 0;
//                 int newR = r + move.first;
//                 int newC = 1;
//                 if (newR >= 0 && newR < ROW && newC >= 0 && newC < COL && grid[newR][newC] > grid[r][0]) {
//                     DFS(newR, newC, grid, count);
//                 }

//                 maxCount = max(maxCount, count);

//                 if (maxCount == COL - 1) {
//                     // break;
//                     return maxCount;
//                 }
//             }

//             // maxCount = max(maxCount, count);
//         }

//         return maxCount;
//     }
// };


