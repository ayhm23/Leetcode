class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //keep max freq sliding window;
        unordered_map<int, int> freq;
        int maxF = 0, len = 0;
        int n = nums.size();
        for(int l = 0, r = 0; r < n; r++){
            freq[nums[r]]++;
            maxF = max(maxF, freq[nums[r]]);

            while(l <= r && maxF > k){
                //invalid is nums[r]
                if(--freq[nums[l]] == 0) freq.erase(nums[l]);
                if(nums[l] == nums[r]) maxF--;
                l++;
            }

            len = max(len, r - l + 1);
        } 
        return len;
    }
};