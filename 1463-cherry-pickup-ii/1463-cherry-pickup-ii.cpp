class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, 0))
        );

        // base row
        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){
                if(j1 == j2)
                    dp[r-1][j1][j2] = grid[r-1][j1];
                else
                    dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i = r-2; i >= 0; i--){
            for(int j1 = 0; j1 < c; j1++){
                for(int j2 = 0; j2 < c; j2++){

                    int best = 0;

                    for(int d1 = -1; d1 <= 1; d1++){
                        for(int d2 = -1; d2 <= 1; d2++){

                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if(nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c)
                                best = max(best, dp[i+1][nj1][nj2]);
                        }
                    }

                    int cherries;
                    if(j1 == j2)
                        cherries = grid[i][j1];
                    else
                        cherries = grid[i][j1] + grid[i][j2];

                    dp[i][j1][j2] = cherries + best;
                }
            }
        }

        return dp[0][0][c-1];
    }
};