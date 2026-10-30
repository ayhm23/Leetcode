class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> d(n, vector<int>(k + 1, INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;

        d[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [w, u, c] = pq.top();
            pq.pop();

            if(w != d[u][c]) continue;
            if(u == n - 1) return w;

            for(auto& [v, wt] : adj[u]) {
                int nc = labels[u] == labels[v] ? c + 1 : 1;
                if(nc > k) continue;

                if(w + wt < d[v][nc]) {
                    d[v][nc] = w + wt;
                    pq.push({w + wt, v, nc});
                }
            }
        }

        return -1;
    }
};