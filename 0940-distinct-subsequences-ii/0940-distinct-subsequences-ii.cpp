class Solution {
public:
    int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.length();

        using ll = long long;

        vector<int> dp(n+1, 0);
        dp[0] = 1;

        unordered_map<char, int> last;

        for(int i = 1; i <= n; i++){
            int prevIdx = last.count(s[i-1]) ? last[s[i-1]] : 0;
            int prev = (prevIdx == 0 ? 0 : dp[prevIdx-1]);  
            dp[i] = (2LL*dp[i-1] % MOD - prev + MOD)%MOD;
            last[s[i-1]] = i; 
        }
        return (dp[n] - 1 + MOD)%MOD;
    }
};