class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int smap [26] = {}, tmap[26] = {};
        for(int i = 0; i < s.size(); i++){
            smap[s[i] - 'a']++;
            tmap[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(smap[i] != tmap[i]) return false;
        }
        return true;
    }
};