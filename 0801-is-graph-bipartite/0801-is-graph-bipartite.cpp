class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1: unvisited, 0 & 1: two colors
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) { // Only process unvisited components
                queue<int> q;
                q.push(i);
                color[i] = 0; // Start with color 0

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int neighbour : graph[node]) {
                        if(color[neighbour] == -1) { // Only color unvisited nodes
                            color[neighbour] = !color[node]; // Assign opposite color
                            q.push(neighbour);
                        } 
                        else if(color[neighbour] == color[node]) { 
                            return false; // Conflict detected
                        }
                    }
                }
            }
        }
        return true;
    }
};
