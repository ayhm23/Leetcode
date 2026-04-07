class Solution {
public:
    char getMirror(char c) {
        if (c >= '0' && c <= '9') {
            return '9' - (c - '0');
        } else {
            return 'z' - (c - 'a');
        }
    }
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        unordered_set<char> seen;
        int ans = 0;
        for (auto &it : freq) {
            char c = it.first;
            if (seen.count(c)) continue;
            char m = getMirror(c);
            int freqM = freq.count(m) ? freq[m] : 0;
            ans += abs(it.second - freqM);
            seen.insert(c);
            seen.insert(m);
        }
        return ans;
    }
};