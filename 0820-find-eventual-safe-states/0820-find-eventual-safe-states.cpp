class Solution {
private:
    void dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> &safe, vector<vector<int>> &graph){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                dfs(it, vis, pathvis, safe, graph);
            }
            if(pathvis[it]){ // Cycle detected
                safe[node] = 0;
                return;
            }
        }

        safe[node] = 1;  // Mark node as safe only after checking all neighbors
        pathvis[node] = 0;  // Backtrack
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safe(n, 0); // Initially, assume all nodes are unsafe

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, safe, graph);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]){  // Collect safe nodes
                ans.push_back(i);
            }
        }
        return ans;
    }
};
