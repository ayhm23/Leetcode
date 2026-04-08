class Solution {
public:
    // int DP(vector<int>&arr, int k, int i, vector<int>&dp){
    //     if(i >= arr.size()) return 0;
    //     //from i...move a window starting from size 1 to k that makes valid windows
    //     if(dp[i] != -1) return dp[i];
    //     int maxi = 0;
    //     for(int j = i; j < i+k; j++){
    //         if(j >= arr.size()) continue;
    //         int elem = *max_element(arr.begin() + i, arr.begin() + j + 1);
    //         int size = j - i + 1;
    //         int ops = elem*size + DP(arr, k, j+1, dp);
    //         maxi = max(ops, maxi);
    //     }
    //     dp[i] = maxi;
    //     cout << dp[i] << " " << i << " ";
    //     return dp[i];
    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp (n + 1,  -1);
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--){
            int maxi = 0;
            for(int j = i; j < i + k && j < n; j++){
                int elem = *max_element(arr.begin() + i, arr.begin() + j + 1);
                int size = j - i + 1;

                int ops = elem*size + dp[j+1];
                maxi = max(maxi, ops);
            }
            dp[i] = maxi;
        }
        return dp[0];   
    }
};