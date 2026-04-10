class Solution {
public:
    int atmost(string s, int k){
        unordered_map<char, int> mp;
        int l = 0, ans = 0;

        for(int r = 0; r < s.length(); r++){
            mp[s[r]]++;

            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            ans += r - l + 1; 
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return atmost(s, 3) - atmost(s, 2);
    }
};