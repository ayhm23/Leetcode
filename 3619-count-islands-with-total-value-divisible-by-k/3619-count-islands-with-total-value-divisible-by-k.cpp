class Solution {
public:
    int m, n;
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    long long dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y) {
        stack<pair<int,int>> st;
        st.push({x, y});
        vis[x][y] = 1;

        long long sum = 0;

        while(!st.empty()) {
            auto [x, y] = st.top();
            st.pop();

            sum += grid[x][y];

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny] || grid[nx][ny] == 0) continue;

                vis[nx][ny] = 1;
                st.push({nx, ny});
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 || vis[i][j]) continue;

                long long val = dfs(grid, vis, i, j);
                if(val % k == 0) cnt++;
            }
        }

        return cnt;
    }
};