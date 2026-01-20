class Solution {
public:
    void sub(vector<vector<int>>& ans, vector<int>& nums,
             vector<int>& curr, int i) {

        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Exclude nums[i]
        sub(ans, nums, curr, i + 1);

        // Include nums[i]
        curr.push_back(nums[i]);
        sub(ans, nums, curr, i + 1);
        curr.pop_back(); // backtracking
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sub(ans, nums, curr, 0);
        return ans;
    }
};
