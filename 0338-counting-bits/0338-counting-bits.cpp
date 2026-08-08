class Solution {
public:
    vector<int> countBits(int n) {
        //if lsb is 1..then count sam eas prev..else if same 
        // the pattern repeats to the last calculated --- in the powers of 2 

        vector<int> dp(n+1, 0);
        int sub = 1;
        for(int i = 1; i <= n; i++){
            if(sub * 2 == i) sub = i; 
            dp[i] = dp[i - sub] + 1;
        }
        return dp;
    }
};