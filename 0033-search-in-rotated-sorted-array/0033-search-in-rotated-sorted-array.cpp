class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            //check which side is sorted
            if(nums[mid] >= nums[lo]){//left sort 
                if(target < nums[mid] && target >= nums[lo]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{// right sorted
                if(target <= nums[hi] && target > nums[mid]){
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return -1;
    }
};