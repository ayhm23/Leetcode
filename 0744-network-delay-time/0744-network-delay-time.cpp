class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1-based indexing: node numbers are 1 to n
        vector<vector<pair<int, int>>> adj(n + 1); // adj[u] = {{v, wt}, ...}
        
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Dijkstra's Algorithm
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue; // Already found better path

            for (auto [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
