class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;
        vector<int> topoSort;


        for(auto it : prerequisites){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topoSort.push_back(curr);

            for(auto it : adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topoSort.size() == numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};