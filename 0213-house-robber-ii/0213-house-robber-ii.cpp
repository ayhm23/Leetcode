class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        // Case 1: rob houses 0 → n-2
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n-1; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        int ans1 = prev1;

        // Case 2: rob houses 1 → n-1
        if(nums.size() == 2) return max(nums[0],nums[1]);
        prev2 = nums[1];
        prev1 = max(nums[1], nums[2]);

        for(int i = 3; i < n; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        int ans2 = prev1;

        return max(ans1, ans2);
    }
};