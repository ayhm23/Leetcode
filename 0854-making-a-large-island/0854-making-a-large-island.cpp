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

    long long getSize(int u){
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

    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            if(grid[i][j] == 1){
                ll hashP = (ll(i) << 16) | j;
                for (int x = 0; x < 4; x++) {
                    int adjx = i + delrow[x];
                    int adjy = j + delcol[x];
                    if (adjx >= 0 && adjx < n && adjy >= 0 && adjy < n && grid[adjx][adjy] == 1) {
                        ll adjhash = (ll(adjx) << 16) | adjy;
                        if (ds.findUPar(hashP) != ds.findUPar(adjhash)) {
                            ds.unionBySize(hashP, adjhash);
                        }
                    }
                }
            }
        }
    }
    if(ds.getSize(0) == n*n)return n*n;
    long long maxcount = 0;
    for(int x = 0;x < n; x++){
        for(int y = 0;y < n; y++){
            if(grid[x][y] == 0){
                int x0 = x + delrow[0], y0 = y + delcol[0];
                int x1 = x + delrow[1], y1 = y + delcol[1];
                int x2 = x + delrow[2], y2 = y + delcol[2];
                int x3 = x + delrow[3], y3 = y + delcol[3];

                // Set to track unique parent nodes
                unordered_set<long long> uniqueParents;

                // Check all 4 adjacent positions
                vector<pair<int, int>> neighbors = {{x0, y0}, {x1, y1}, {x2, y2}, {x3, y3}};

                for (auto [nx, ny] : neighbors) {
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        long long adjHash = (nx << 16) | ny;
                        uniqueParents.insert(ds.findUPar(adjHash)); // Store unique parent
                    }
                }
                ll  temp = 0;
                for (auto parentHash : uniqueParents) {
                    temp+=ds.getSize(parentHash);
                }
                maxcount = max(maxcount, temp);
            }
        }
    }
    return maxcount+1;
    }
};