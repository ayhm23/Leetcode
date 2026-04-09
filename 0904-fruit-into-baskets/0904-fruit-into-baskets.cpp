class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int r = 0, l = 0;
        int n = fruits.size(), k = 2, ans = 0;;

        while(r < n){
            mp[fruits[r]]++;
            if(mp.size() > k){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            else{
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};