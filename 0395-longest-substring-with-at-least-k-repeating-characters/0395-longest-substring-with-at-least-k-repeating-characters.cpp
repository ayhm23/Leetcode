class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        if(s.length()<k) return 0;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Find first "bad" character that appears less than k times
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                // Split the string at the breaking point
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }

        // If there is no breaking point, the entire string is valid
        return s.size();
    }
};