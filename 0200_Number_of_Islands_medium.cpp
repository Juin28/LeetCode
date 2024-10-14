class Solution {
public:
    bool validPoint(int r, int c, int maxRows, int maxCols) {
        return r >= 0 && r < maxRows && c >= 0 && c < maxCols;
    }

    void markIslandToWater(vector<vector<char>>& grid, int r, int c, int maxRows, int maxCols) {
        queue< pair<int, int> > q;
        q.push({r, c});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            pair<int, int> possibleMoves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (pair<int, int>& move : possibleMoves) {
                int newR = r + move.first;
                int newC = c + move.second;

                if (validPoint(newR, newC, maxRows, maxCols) && grid[newR][newC] == '1') {
                    q.push({newR, newC});
                    grid[newR][newC] = '0'; 
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int maxRows = grid.size();
        int maxCols = grid[0].size();

        int numberOfIslands = 0;

        for (int r = 0; r < maxRows; ++r) {
            for (int c = 0; c < maxCols; ++c) {
                if (grid[r][c] == '1') {
                    numberOfIslands++;
                    markIslandToWater(grid, r, c, maxRows, maxCols);
                }
            }
        }

        return numberOfIslands;
    }
};
