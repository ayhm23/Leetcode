class Solution {
public:
    void sums(vector<vector<int>> &ans, vector<int>& nums, int idx, 
    int k, int n, vector<int> & curr, int sum){
        if (curr.size() == k) {
            if (sum == n)
                ans.push_back(curr);
            return;
        }

        if (idx == nums.size() || sum > n) return;


        curr.push_back(nums[idx]);
        sums(ans, nums, idx+1, k, n, curr, sum+nums[idx]);
        curr.pop_back();

        sums(ans, nums, idx+1, k, n, curr, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;

        sums(ans, nums, 0, k, n, curr, 0);
        return ans;
    }
};