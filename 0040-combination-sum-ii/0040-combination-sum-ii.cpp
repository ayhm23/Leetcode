class Solution {
public:
    vector<vector<int>> ans;
    void count(vector<int>& candidates, int target, vector<int>&curr, int sum, int i){
        if(sum == target){
            ans.push_back(curr); return;
        }
        if(i == candidates.size() || sum > target) return;

        //if not taking..then skip dupilicate elemnets
        int j = i;
        while(j < candidates.size() && candidates[j] == candidates[i]) j++;
        count(candidates, target, curr, sum, j);

        curr.push_back(candidates[i]);
        count(candidates, target, curr, sum + candidates[i], i+1);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        count(candidates, target, curr, 0, 0);
        return ans;
    }
};