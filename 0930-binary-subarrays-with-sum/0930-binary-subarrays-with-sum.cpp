class Solution {
public:
    int count(const vector<int> &nums, int goal){
        int count = 0;
        for(int lo = 0, hi = 0, sum = 0; hi < nums.size(); hi++){
            sum += nums[hi];
            while(sum > goal && lo <= hi) {
                sum -= nums[lo]; lo++;
                }
            count += (hi - lo + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums, goal) - count(nums, goal-1);
    }
};