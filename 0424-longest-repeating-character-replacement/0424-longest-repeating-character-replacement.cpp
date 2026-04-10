class Solution {
public:
    int characterReplacement(string s, int k) {
        int buffer = 0;
        unordered_map<char, int> mp;

        int l = 0, r = 0, n = s.length();
        int maxF = 0, ans = 0;

        while(r < n){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);
            int currLen = r - l + 1;
            int extra =  currLen - maxF;
            if(extra > k){
                if(--mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }

            ans = max(r - l + 1, ans);
            r++;
        }
        return ans;
    }
};