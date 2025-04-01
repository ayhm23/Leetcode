class DisjointSet {
public: 
    vector<int> rank, parent, size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;  // Not enough cables to connect all

        DisjointSet ds(n);
        int redundant = 0;
        
        for (auto& it : connections) {
            int u = it[0], v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                redundant++;  // This cable is redundant
            } else {
                ds.unionBySize(u, v);
            }
        }

        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {  // Count root parents
                connectedComponents++;
            }
        }

        int required = connectedComponents - 1;
        return (redundant >= required) ? required : -1;
    }
};