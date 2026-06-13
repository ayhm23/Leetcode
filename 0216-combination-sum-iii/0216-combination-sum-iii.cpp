class Solution {
public:
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;

    void count(int k, int n, vector<int> &curr, int ind){
        if(curr.size() == k){
            if(n == 0) ans.push_back(curr); 
            return;
        }
        
        if(n < 0 || ind == 9) return;

        count(k, n, curr, ind + 1);

        curr.push_back(nums[ind]);
        count(k, n - nums[ind], curr, ind + 1);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        count(k, n, curr, 0);
        return ans;
    }
};