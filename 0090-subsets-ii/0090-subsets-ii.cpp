class Solution {
public:

    void subset(vector<vector<int>> &ans, int idx, vector<int> &curr, vector<int> &nums){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        //include
        curr.push_back(nums[idx]);
        subset(ans, idx+1, curr, nums);
        curr.pop_back();

        int next = idx + 1;
        while(next < nums.size() && nums[idx] == nums[next]) next++;
        subset(ans, next, curr, nums);
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr; vector<vector<int>> ans;
        subset(ans, 0, curr, nums);
        return ans;
    }
};