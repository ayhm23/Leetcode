class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> vis;

    bool dfs(int i, vector<int>& topo){
        vis[i] = 1;

        for(int v : adjList[i]){
            if(vis[v] == 1) return false; // cycle

            if(vis[v] == 0){
                if(!dfs(v, topo))
                    return false;
            }
        }

        vis[i] = 2;
        topo.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        int n = numCourses;

        adjList.assign(n, {});
        vis.assign(n, 0);

        for(auto &it : prerequisites){
            int u = it[0], v = it[1];
            adjList[v].push_back(u); // prerequisite -> course
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(!dfs(i, topo))
                    return {};
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};