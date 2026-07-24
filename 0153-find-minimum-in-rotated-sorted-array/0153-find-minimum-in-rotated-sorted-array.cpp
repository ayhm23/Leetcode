class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     //find peak..next element will be min
    //     int lo = 0, hi = nums.size()-1, n = nums.size();
    //     while(lo < hi){
    //         int mid = lo + (hi-lo)/2;
    //         if(nums[mid] > nums[hi]) lo = mid+1;
    //         else hi = mid;
    //     }
    //     return nums[lo];
    // }
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;

        while(l <= r){
            // already sorted
            if(nums[l] <= nums[r]){
                ans = min(ans, nums[l]);
                break;
            }

            int mid = l + (r-l)/2;

            // left part sorted
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            // right part sorted
            else{
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }

        return ans;
    }
};