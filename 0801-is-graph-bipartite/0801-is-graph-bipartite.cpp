class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1: Unvisited, 0: Red, 1: Blue
        
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;  // Skip already colored components
            
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Start coloring from 0
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = !color[node];  // Assign opposite color
                        q.push(neighbor);
                    } 
                    else if (color[neighbor] == color[node]) {
                        return false;  // Conflict detected
                    }
                }
            }
        }
        return true;  // Graph is bipartite
    }
};