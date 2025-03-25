class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q; // { {row, col}, time }
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Add all initially rotten oranges to queue
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 2) {
                    q.push({{row, col}, 0});
                    visited[row][col] = 1; // Mark visited
                }
            }
        }

        int tm = 0;
        vector<int> delrow = {0, -1, 0, 1};
        vector<int> delcol = {-1, 0, 1, 0};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check valid cell and fresh orange
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    
                    visited[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2; // Make it rotten
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        // Check if any fresh oranges remain
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    return -1; // Not all oranges are rotten
                }
            }
        }

        return tm;
    }
};