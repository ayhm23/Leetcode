class Solution {
public:
    void sub(vector<vector<int>> &ans, vector<int>& nums, int i, vector<int> &curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        int temp = nums[i];
        sub(ans, nums, i+1, curr);
        curr.push_back(temp);
        sub(ans, nums, i+1, curr);
        curr.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sub(ans, nums, 0, curr);
        return ans;
    }
};