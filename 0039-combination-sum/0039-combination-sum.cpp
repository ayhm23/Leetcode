class Solution {
public:
    vector<vector<int>> ans;
    void count(vector<int>& candidates, int target, vector<int>&curr, int sum, int i){
        if(sum == target){
            ans.push_back(curr); return;
        }
        if(i == candidates.size() || sum > target) return;

        count(candidates, target, curr, sum, i+1);

        curr.push_back(candidates[i]);
        count(candidates, target, curr, sum + candidates[i], i);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        count(candidates, target, curr, 0, 0);
        return ans;
    }
};