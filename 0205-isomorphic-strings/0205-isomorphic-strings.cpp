class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        int smap [256] = {}, tmap [256] = {};
        for(int i = 0; i < s.size(); i++){
            if(smap[s[i]] != tmap[t[i]]) return false;
            smap[s[i]] = tmap[t[i]] = i + 1;
        }
        return true;
    }
};