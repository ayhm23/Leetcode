class Solution {
public:
    int ans(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0 ,sum = 0, count = 0;
        
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r] % 2;
            
            while(sum > k){
                sum -= nums[l++]%2;
            }
            count += (r - l + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return ans(nums, k) - ans(nums, k-1);
    }
};