// BFS - Optimal Solution
class Solution {
public:
    bool isValidWater(vector<vector<int>>& grid, int newX, int newY) {
        int numRow = grid.size();
        int numCol = grid[0].size();

        return (newX >= 0 && newX < numCol && newY >= 0 && newY < numRow && grid[newY][newX] != 0);
    }
    int catchFishes(vector<vector<int>>& grid, int x, int y) {
        int numRow = grid.size();
        int numCol = grid[0].size();
        vector<pair<int, int>> waters;

        int numFishes = 0;
        waters.push_back({x, y});

        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!waters.empty()) {
            pair<int, int>& water = waters.back();
            int waterX = water.first;
            int waterY = water.second;
            numFishes += grid[waterY][waterX];
            grid[waterY][waterX] = 0;
            waters.pop_back();

            for (auto& move: moves) {
                int newX = waterX + move.first;
                int newY = waterY+ move.second;

                if (isValidWater(grid, newX, newY)) {
                    waters.push_back({newX, newY});
                }
            }
        }

        return numFishes;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFishes = 0;
        int numRow = grid.size();
        int numCol = grid[0].size();

        for (int r = 0; r < numRow; ++r) {
            for (int c = 0; c < numCol; ++c) {
                if (grid[r][c] == 0) {
                    continue;
                }

                int numFishes = catchFishes(grid, c, r);
                maxFishes = max(maxFishes, numFishes);
            }
        }

        return maxFishes;
    }
};

// DFS
// class Solution {
// public:
//     int catchFishes(vector<vector<int>>& grid, int x, int y) {
//         int numRow = grid.size();
//         int numCol = grid[0].size();

//         int numFishes = grid[y][x];
//         grid[y][x] = 0;
    
//         vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         for (auto& move: moves) {
//             int newX = x + move.first;
//             int newY = y + move.second;

//             if (newX < 0 || newX >= numCol || newY < 0 || newY >= numRow) {
//                 continue;
//             }

//             if (grid[newY][newX] == 0) {
//                 continue;
//             } else {
//                 numFishes += catchFishes(grid, newX, newY);
//             }
//         }

//         return numFishes;
//     }

//     int findMaxFish(vector<vector<int>>& grid) {
//         int maxFishes = 0;
//         int numRow = grid.size();
//         int numCol = grid[0].size();

//         for (int r = 0; r < numRow; ++r) {
//             for (int c = 0; c < numCol; ++c) {
//                 if (grid[r][c] == 0) {
//                     continue;
//                 }

//                 int numFishes = catchFishes(grid, c, r);
//                 maxFishes = max(maxFishes, numFishes);
//             }
//         }

//         return maxFishes;
//     }
// };

