class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> s;

        // Step 1: Push all border land cells (1s) into the stack
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 && (row == 0 || row == m - 1 || col == 0 || col == n - 1)) {
                    s.push({row, col});
                    grid[row][col] = 0; // Mark as visited
                }
            }
        }

        vector<int> delrow = {0, -1, 0, 1};
        vector<int> delcol = {-1, 0, 1, 0};

        // Step 2: DFS to remove all border-connected lands
        while (!s.empty()) {
            auto [row, col] = s.top();
            s.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i], ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if (grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 0; // Mark as visited
                        s.push({nrow, ncol});
                    }
                }
            }
        }

        // Step 3: Count remaining land cells (1s)
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};