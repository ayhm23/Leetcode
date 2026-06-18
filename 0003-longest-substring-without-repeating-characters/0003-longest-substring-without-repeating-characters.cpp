class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mp;
        int ans = 0;
        
        for(int hi = 0, lo = 0; hi < s.length(); hi++){
            mp[s[hi]]++;
            while(mp[s[hi]] > 1 && lo < hi){
                mp[s[lo++]]--;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};