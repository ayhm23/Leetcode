class Solution {
public:
    bool isAnagram(string s, string t) {
        //sol 1 : sort both and compare
        //sol 2 : maintain frequeny of the 26 character O(N) O(1)
        if(s.size() != t.size()) return false;

        int freq[26] = {0};

        for(char c : s) freq[c - 'a']++;
        for(char c : t) freq[c - 'a']--;

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};
