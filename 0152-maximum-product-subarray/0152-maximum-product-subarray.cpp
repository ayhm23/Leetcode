class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int tempMx = max({x, x * mx, x * mn});
            int tempMn = min({x, x * mx, x * mn});

            mx = tempMx;
            mn = tempMn;

            ans = max(ans, mx);
        }

        return ans;
    }
};