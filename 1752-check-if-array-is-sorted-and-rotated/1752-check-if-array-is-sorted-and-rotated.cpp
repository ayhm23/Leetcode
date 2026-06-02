class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i], next = nums[(i+1)%nums.size()];
            if(curr > next) cnt++;
            if(cnt > 1) return false;
        }
        return true;
    }
};