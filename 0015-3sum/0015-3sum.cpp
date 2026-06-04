class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); int n = nums.size();
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int curr = nums[i];//find two nums with sum -curr //already sorted only need 2 poninter l and r
            int l = i+1, r = n-1;
            while(l < r){
                int s = nums[l] + nums[r] + curr;
                if(s == 0){
                    ans.push_back({curr, nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1])l++;
                    while(l < r && nums[r] == nums[r-1])r--;
                    l++; r--;
                }
                else if(s < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};