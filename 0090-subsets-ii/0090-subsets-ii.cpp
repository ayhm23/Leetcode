class Solution {
public:
    vector<vector<int>> ans;

    void subset(vector<int> &nums, int i, vector<int>& curr){
        if(i == nums.size()){
            ans.push_back(curr); return;
        }
        int j = i;
        while(j < nums.size() && nums[j] == nums[i]) j++;
        subset(nums, j, curr);

        curr.push_back(nums[i]);
        subset(nums, i + 1, curr);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        subset(nums, 0, curr);
        return ans;
    }
};