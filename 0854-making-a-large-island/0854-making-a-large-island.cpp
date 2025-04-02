class DisjointSet {
    unordered_map<long long, long long> parent, size;

public:
    // Find with path compression
    long long findUPar(long long node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node; // Lazy initialization
            size[node] = 1;      // Initialize size to 1
        }
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    // Union by Size
    void unionBySize(long long u, long long v) {
        long long pu = findUPar(u);
        long long pv = findUPar(v);
        
        if (pu != pv) {
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    }

    long long getSize(long long u) {
        return size[findUPar(u)];
    }
};

typedef long long ll;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        DisjointSet ds;
        int n = grid.size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        bool hasZero = false;
        long long maxIslandSize = 0;

        // Step 1: Union all connected components of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ll hashP = (ll(i) << 16) | j;
                    for (int x = 0; x < 4; x++) {
                        int adjx = i + delrow[x];
                        int adjy = j + delcol[x];
                        if (adjx >= 0 && adjx < n && adjy >= 0 && adjy < n && grid[adjx][adjy] == 1) {
                            ll adjhash = (ll(adjx) << 16) | adjy;
                            ds.unionBySize(hashP, adjhash);
                        }
                    }
                } else {
                    hasZero = true; // Mark that there is at least one '0'
                }
            }
        }

        // Step 2: Find the largest connected component
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxIslandSize = max(maxIslandSize, ds.getSize((ll(i) << 16) | j));
                }
            }
        }

        // If the entire grid is already filled with 1s, return the size
        if (!hasZero) return n * n;

        // Step 3: Try flipping every 0 to 1 and compute max island
        long long maxcount = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 0) {
                    unordered_set<long long> uniqueParents;
                    for (int d = 0; d < 4; d++) {
                        int nx = x + delrow[d], ny = y + delcol[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            uniqueParents.insert(ds.findUPar((ll(nx) << 16) | ny));
                        }
                    }
                    
                    // Sum sizes of unique adjacent islands
                    ll temp = 1; // Count the new cell itself
                    for (auto parentHash : uniqueParents) {
                        temp += ds.getSize(parentHash);
                    }
                    maxcount = max(maxcount, temp);
                }
            }
        }
        return maxcount;
    }
};
