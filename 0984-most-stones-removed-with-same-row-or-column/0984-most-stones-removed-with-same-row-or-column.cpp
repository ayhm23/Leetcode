class DisjointSet {
public:
    unordered_map<int, int> parent, rank;

    int findUPar(int node) {
        if (parent.find(node) == parent.end()) parent[node] = node; // Lazy init
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) parent[pv] = pu;
            else if (rank[pu] < rank[pv]) parent[pu] = pv;
            else { parent[pv] = pu; rank[pu]++; }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet ds;
        for (auto& s : stones) {
            ds.unionByRank(s[0], ~s[1]);  // Use ~col to avoid row-col conflicts
        }

        unordered_map<int, int> components;
        for (auto& s : stones) {
            components[ds.findUPar(s[0])] = 1;
        }

        int numComponents = components.size();
        return stones.size() - numComponents;
    }
};