class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        vector<int> req(128, 0);        // required frequency from t
        for (char c : t) {
            req[c]++;
        }
        
        int left = 0;
        int required = t.size();        // how many chars we still need
        int formed = 0;                 // how many unique chars we have satisfied
        int minLen = INT_MAX;
        int minStart = 0;
        
        vector<int> window(128, 0);     // current window frequency
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            
            // If this char is needed and we just satisfied its count
            if (req[c] > 0 && window[c] <= req[c]) {
                formed++;
            }
            
            // Try to shrink the window from left as much as possible
            while (formed == required && left <= right) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                char leftChar = s[left];
                window[leftChar]--;
                
                if (req[leftChar] > 0 && window[leftChar] < req[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};