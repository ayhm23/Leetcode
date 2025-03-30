class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> edges(n);
        for (auto it : flights) {
            edges[it[0]].emplace_back(it[1], it[2]);
        }   

        queue<pair<int, pair<int, int>>> q;
        vector<int> distance (n, INT_MAX);

        distance[src] = 0;
        q.push({0, {src, 0}}); //stops, node, dist
    
        while(!q.empty()) {
            int currStop = q.front().first;
            int currNode = q.front().second.first;
            int currDist = q.front().second.second;
            q.pop();

            if(currStop > k) continue;

            for(auto it : edges[currNode]) {
                int nextNode = it.first;
                int cost = it.second;
                
                if(currDist + cost < distance[nextNode]) {
                    distance[nextNode] = currDist + cost;
                    q.push({currStop + 1, {nextNode, distance[nextNode]}});
                }
            }
        }

        return distance[dst] != INT_MAX ? distance[dst] : -1;
    }
};