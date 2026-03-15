// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         //dp[i][j] is minimum sum for (i, j) cell

//         int m = grid.size(), n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//         dp[0][0] = grid[0][0];
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(!(i+j)) continue;

//                 int top = i-1 >= 0 ? dp[i-1][j] : INT_MAX;
//                 int left = j-1 >= 0 ? dp[i][j-1] : INT_MAX; 
            
//                 int curr = min(top, left);
//                 dp[i][j] = grid[i][j] + curr;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

//space opti

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dp[i][j] is minimum sum for (i, j) cell

        int m = grid.size(), n = grid[0].size();

        vector<int> prev(n);
        prev[0] = grid[0][0]; //dp[0][0] = grid[0][0];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!(i+j)) continue;

                int top = i-1 >= 0 ? prev[j] : INT_MAX;
                int left = j-1 >= 0 ? prev[j-1] : INT_MAX; 
            
                int curr = min(top, left);
                prev[j] = grid[i][j] + curr;
            }
        }
        return prev[n-1];
    }
};