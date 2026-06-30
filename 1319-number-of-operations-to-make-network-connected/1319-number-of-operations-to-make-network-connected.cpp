class DisJointSet{
    private:
        vector<int> size, parent;
        int components;
    public:
        DisJointSet(int n){
            size.resize(n, 1);
            parent.resize(n);
            components = n;

            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findP(int n){
            if(parent[n] == n) return n;
            return parent[n] = findP(parent[n]);
        }

        int unionBySize(int a, int b){ //1 - same parent 2 - not same
            int pa = findP(a), pb = findP(b);
            if(pa == pb) return 1;
            else if(size[pa] > size[pb]){
                parent[pb] = pa;
                size[pa] += size[pb];
                components--;
            }
            else{
                parent[pa] = pb;
                size[pb] += size[pa];
                components--;
            }
            return 2;
        }

        int getComponents(){
            return components;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int k = connections.size();
        if(k < n-1) return -1;

        DisJointSet dsu(n);
        int count = 0;
        for(auto &c : connections){
            int a = c[0], b = c[1];
            if(dsu.unionBySize(a, b) == 1) count++; //saved a cable
        }

        int totalC = dsu.getComponents();

        return totalC-1 <= count ? totalC-1 : -1;
    }
};