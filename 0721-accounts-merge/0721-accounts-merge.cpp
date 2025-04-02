class DisjointSet {
    public: 
        vector<int> rank, parent, size;
        DisjointSet(){
            
        }
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
    
        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
    
        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];  // Fixed: was `size[ulp_v] += size[ulp_v]`
            }
        }
    };
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> Mailmap;
        int num = -1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(Mailmap.find(mail) == Mailmap.end()){
                    Mailmap.insert({mail, i});
                }
                else{
                    //found existing mail 
                    ds.unionBySize(i, Mailmap[mail]);
                }
            }
        }
        vector<vector<string>> mergedmail(n);

        for(auto it : Mailmap){
            string mail = it.first;
            int node = it.second;
            mergedmail[ds.findUPar(node)].push_back(mail);

        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergedmail[i].size() == 0) continue;
            sort(mergedmail[i].begin(), mergedmail[i].end()); // ✅ Sort each vector individually

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};