class Solution {
public:
    void backtrack(int start, int remain, vector<int>& candidates,
                   vector<int>& path, vector<vector<int>>& ans) {

        if (remain == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) break;

            path.push_back(candidates[i]);
            backtrack(i, remain - candidates[i], candidates, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 🔑 pruning
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, target, candidates, path, ans);
        return ans;
    }
};
