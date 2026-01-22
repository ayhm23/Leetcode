class Solution {
public:

    void combination(vector<vector<int>> &ans, int idx, int remain, vector<int> &curr, vector<int> &nums){
        if(remain == 0){
            ans.push_back(curr);
            return;
        }

        if(idx == nums.size() || remain < nums[idx]) return;

        //include next
        curr.push_back(nums[idx]);
        combination(ans, idx+1, remain-nums[idx], curr, nums);
        curr.pop_back();

        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]) next++;

        combination(ans, next, remain, curr, nums);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; vector<int> curr;
        combination(ans, 0, target, curr, candidates);
        return ans;
    }
};