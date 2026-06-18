class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(int lo = 0, hi = 0; hi < fruits.size(); hi++){
            mp[fruits[hi]]++;

            while(mp.size() > 2 && lo <= hi){
                mp[fruits[lo]]--;
                if(mp[fruits[lo]] == 0){
                    mp.erase(fruits[lo]);
                }
                lo++;
            }

            ans = max(hi - lo + 1, ans);
        }
        return ans;
    }
};