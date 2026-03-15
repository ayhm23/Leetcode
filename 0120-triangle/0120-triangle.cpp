class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        dp[0][0] = triangle[0][0];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(i == 0 && j == 0) continue;

                int x = (j < triangle[i-1].size()) ? dp[i-1][j] : INT_MAX; 
                int y = j > 0 ? dp[i-1][j-1] : INT_MAX;

                dp[i][j] = triangle[i][j] + min(x, y);
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};