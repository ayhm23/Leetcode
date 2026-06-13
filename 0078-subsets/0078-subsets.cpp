class Solution {
public:
    vector<vector<int>> ans;

    void subset(vector<int> &nums, int i, vector<int>& curr){
        if(i == nums.size()){
            ans.push_back(curr); return;
        }

        subset(nums, i + 1, curr);

        curr.push_back(nums[i]);
        subset(nums, i + 1, curr);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        subset(nums, 0, curr);
        return ans;
    }
};