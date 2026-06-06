class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //idea is.. if mid + 1 > mid..then peak is to the right/..else <= mid can be peak
        int lo = 0, hi = nums.size()-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] < nums[mid+1]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return hi;
    }
};