class Solution {
public:
    void summ(vector<vector<int>> &ans, vector<int> &curr, int sum, int i, vector<int>& candidates, int k){
        if(sum == k){
            ans.push_back(curr);
            return;
        }
        if(sum > k || i == candidates.size()) return;

        int n = candidates[i];

        //not include;
        summ(ans, curr, sum, i + 1, candidates, k);

        //include

        curr.push_back(n);
        sum+=n;

        summ(ans, curr, sum, i, candidates, k);

        curr.pop_back();
        sum-=n;        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        summ(ans, curr, 0, 0, candidates, target);
        return ans;
    }
};