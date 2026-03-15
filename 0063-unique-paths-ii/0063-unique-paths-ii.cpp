class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //dp[obstacle] = 0
        //dp[i][j] is number of unique paths

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        vector<int> prev(n, -1);
        prev[0] = 1; //dp [0][0]

        if(obstacleGrid[0][0])  return 0;

        // dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!i && !j) continue;
                if(obstacleGrid[i][j] == 1) {
                    prev[j] = 0;
                    continue;
                }

                int top =  (i-1 >= 0 && obstacleGrid[i-1][j] == 0) ? prev[j] : 0;
                int left =  (j-1 >= 0 && obstacleGrid[i][j-1] == 0) ? prev[j-1] : 0;

                int curr = top + left;
                prev[j] = curr;
            }
        }

        return prev[n-1];
    }
};