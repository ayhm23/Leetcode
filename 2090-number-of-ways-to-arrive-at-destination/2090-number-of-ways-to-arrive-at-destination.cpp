class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Graph representation
        vector<vector<pair<int, int>>> edges(n);
        for (auto it : roads) {
            edges[it[0]].emplace_back(it[1], it[2]);
            edges[it[1]].emplace_back(it[0], it[2]);
        }

        // Dijkstra's setup
        vector<long long> time(n, LLONG_MAX); // Use long long to handle large values
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Starting point
        time[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {time, node}

        while (!pq.empty()) {
            long long currTime = pq.top().first; // Use long long
            int currNode = pq.top().second;
            pq.pop();

            if (currTime > time[currNode]) continue;

            for (auto it : edges[currNode]) {
                int nextNode = it.first;
                int travelTime = it.second;
                long long newTime = currTime + travelTime; // Use long long

                // Found a shorter path
                if (newTime < time[nextNode]) {
                    time[nextNode] = newTime;
                    ways[nextNode] = ways[currNode];
                    pq.push({newTime, nextNode});
                }
                // Found another shortest path
                else if (newTime == time[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[currNode]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
