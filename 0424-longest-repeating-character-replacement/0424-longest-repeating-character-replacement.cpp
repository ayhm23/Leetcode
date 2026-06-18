class Solution {
public:
    int characterReplacement(string s, int k) {
        if(!s.length()) return 0;

        unordered_map<char, int> mp;

        int ans = 0, maxFreq = 0;
        for(int lo = 0, hi = 0; hi < s.length(); hi++){
            mp[s[hi]]++;

            maxFreq = max(maxFreq, mp[s[hi]]);

            while((hi - lo + 1 - maxFreq) > k){
                mp[s[lo]]--;
                // maxFreq = max(maxFreq, mp[s[lo]]);
                lo++;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};