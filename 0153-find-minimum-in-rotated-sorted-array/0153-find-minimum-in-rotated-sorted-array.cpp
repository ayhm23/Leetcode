class Solution {
public:
    int findMin(vector<int>& nums) {
        //find peak..next element will be min
        int lo = 0, hi = nums.size()-1, n = nums.size();
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[hi]) lo = mid+1;
            else hi = mid;
        }
        return nums[lo];
    }
};