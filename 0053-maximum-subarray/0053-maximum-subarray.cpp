class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr = -10000, maxx = -10000;
        for(int i = 0; i < nums.size(); i++){
            curr = max(nums[i], curr + nums[i]);
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};