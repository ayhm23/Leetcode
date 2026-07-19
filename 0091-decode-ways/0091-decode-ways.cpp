class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || (!s.empty() && s[0] == '0')) return 0;
        int n = s.length();

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            if(s[i-1] != '0') dp[i] += dp[i-1];
            string str = s.substr(i-2, 2);
            if(stoi(str) >= 10 && stoi(str) <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};