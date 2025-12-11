class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //keep best and current count in kadane's algo
        //approach 1 : BF : make all possible subarrays O(n^2) O(1)
        //approach 2 : Kadane's algo

        long long best = nums[0];
        long long curr = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            curr = max((long long)nums[i], curr + (long long)nums[i]);
            best = max(best, curr);
        }

        return (int)best;
    }
};