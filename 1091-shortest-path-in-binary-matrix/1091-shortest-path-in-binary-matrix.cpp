class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(grid[0][0] ==1 || grid[n-1][n-1] ==1) return -1;
        if(n == 1) return 1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps= q.front().second;
            q.pop();
            int dr[] = {-1,-1,-1,0,0,1,1,1};
            int dc[] = {-1,0,1,-1,1,-1,0,1};
            for(int k=0;k<8;k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !vis[nr][nc])
                {
                    if(nr == n-1 && nc == n-1) return steps + 2;
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},steps+1});
                }

            }
        }
        return -1;
    }
};