// class Solution {
// public:

//     int path(int i, int j){

//         if(i == 0 && j == 0) return 1;
//         if(i < 0 || j < 0) return 0;

//         return path(i-1, j) + path(i, j-1);
//     }

//     int uniquePaths(int m, int n) {
//         return path(m-1, n-1);
//     }
// };

// class Solution {
// public:

//     int path(int i, int j, vector<vector<int>>& dp){

//         if(i == 0 && j == 0) return 1;
//         if(i < 0 || j < 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         return dp[i][j] = path(i-1,j,dp) + path(i,j-1,dp);
//     }

//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         return path(m-1,n-1,dp);
//     }
// };


// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n, -1));
        //dp[i][j] stores unique paths to (i, j) place
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != -1) continue;

                int top = i-1 >= 0 ? dp[i-1][j] : 0;
                int left = j-1 >= 0 ? dp[i][j-1] : 0;

                dp[i][j] = top + left;
            }
        }
        return dp[m-1][n-1];
    }
};