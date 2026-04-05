class Solution {
public:
    // memoization
    // int len(vector<int> &nums, int i, int prev, vector<vector<int>>& dp){
    //     if(i == nums.size()) return 0;

    //     if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

    //     int notTake = len(nums, i+1, prev, dp);

    //     int take = 0;
    //     if(prev == -1 || nums[i] > nums[prev]){
    //         take = 1 + len(nums, i+1, i, dp);
    //     }

    //     return dp[i][prev + 1] = max(take, notTake);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 1);
        
    //     int maxi = 1;
    //     for(int i = 1; i < n; i++){
    //         for(int j = 0; j < i; j++){
    //             if(nums[j] < nums[i]){
    //                 dp[i] = max(dp[i], 1 + dp[j]);
    //             }
    //         }
    //         maxi = max(maxi, dp[i]);
    //     }
    //     return maxi;
    // }


//using binary search
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        
        for(int x : nums){
            auto it = lower_bound(temp.begin(), temp.end(), x);

            if(it == temp.end()){
                //not exist.
                temp.push_back(x);
            }
            else{
                *it = x;
            }
        }
        return temp.size();
    }
};