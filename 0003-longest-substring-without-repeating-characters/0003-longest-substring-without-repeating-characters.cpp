class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left = 0, right = 0;
        int n = s.length();

        int ans = 0;

        while(right < n){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                if(--mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};