class Solution {
public:
    void BFS(int node, vector<int> &visited, vector<vector<int>> &isConnected) {
        queue<int> q;
        q.push(node);
        visited[node] = 1; // Mark node as visited

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Explore all neighbors
            for (int i = 0; i < isConnected[curr].size(); i++) {
                if (isConnected[curr][i] == 1 && visited[i] == 0) { 
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Get the number of nodes
        vector<int> visited(n, 0); // Initialize visited array with 0
        int count = 0; // Initialize count of components

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) { // Start BFS for every unvisited node
                count++;
                BFS(i, visited, isConnected);
            }
        }
        return count;
    }
};