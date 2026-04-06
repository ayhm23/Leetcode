class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //order does not matter
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp (n, 1);
        vector<int> prev (n);

        for(int i = 0; i < n; i++) prev[i] = i;

        //dp[i] --- longest subset till ith index.. including ith index
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    prev[i] = j;
                }
            }
        }

        int ind = max_element(dp.begin(), dp.end()) - dp.begin();
        int len = *max_element(dp.begin(), dp.end());
        vector<int> ans (len);
        int p;
        while(len--){
            p = nums[ind];
            if(prev[ind] == ind){
                ans[len] = nums[ind];
                break;
            }
            ans[len] = p;
            ind = prev[ind];
        }
        return ans;
    }
};