class Solution {
public:
    int maxDistance(vector<int>& colors) {
        //either left distance or the right distance
        unordered_map<int, pair<int, int>> mp; //col, ind
        int n = colors.size();

        for(int i = 0; i < n; i++){
            if(!mp.count(colors[i])){
                mp[colors[i]] = {i, i};
            }
            else if(mp[colors[i]].second < i){
                mp[colors[i]].second = i;
            }
        }
        int ans = 0;
        for(auto &[key1, it1] : mp){
            for(auto &[key2, it2] : mp){
                if(key1 == key2) continue;
                ans = max({ans, abs(it1.first - it2.second), abs(it2.first - it1.second)});
            }
        }
        return ans;
    }
};