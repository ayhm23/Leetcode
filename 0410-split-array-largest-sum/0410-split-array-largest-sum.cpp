class Solution {
public:
    bool canSplit(vector<int>& nums, int max, int k){
        int splits = 1, curr = 0;
        for(int x : nums){
            if(x + curr > max){
                splits+=1; curr = x;
            }
            else curr += x;
        }
        return splits <= k ? true : false; 
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int ans = lo;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(canSplit(nums, mid, k)){
                ans = mid; hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};