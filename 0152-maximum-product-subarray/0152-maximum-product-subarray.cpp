class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mn = nums[0], ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];

            // Fix: use 'mn' instead of 'min'
            int tempMN = min({x, x * mx, x * mn});
            int tempMX = max({x, x * mx, x * mn});

            mx = tempMX;
            mn = tempMN;
            
            // Keep track of the maximum product found so far
            ans = max(ans, mx);
        }
        
        return ans;
    }
};