class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // dp[row][col1][col2] = max cherries till this state
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, INT_MIN)));

        dp[0][0][cols - 1] = grid[0][0];
        if(cols > 1) dp[0][0][cols - 1] += grid[0][cols - 1]; // <-- handle same column case

        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = 0; k < cols; k++) {
                    int curr;
                    if(j == k)
                        curr = grid[i][j];
                    else
                        curr = grid[i][j] + grid[i][k];

                    int prev = INT_MIN;      // <-- FIX: declare prev for every state

                    for(int dj = -1; dj <= 1; dj++) {
                        for(int dk = -1; dk <= 1; dk++) {

                            // <-- FIX: previous columns, not next columns
                            int nj = j - dj;
                            int nk = k - dk;

                            if(nj >= 0 && nj < cols && nk >= 0 && nk < cols) {
                                prev = max(prev, dp[i - 1][nj][nk]);
                            }
                        }
                    }

                    // <-- FIX: don't add INT_MIN
                    if(prev != INT_MIN) dp[i][j][k] = curr + prev;
                }
            }
        }

        int ans = INT_MIN;

        for(int j = 0; j < cols; j++) {
            for(int k = 0; k < cols; k++) {
                ans = max(ans, dp[rows - 1][j][k]);
            }
        }

        return ans;
    }
};