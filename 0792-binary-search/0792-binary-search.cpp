class Solution {
    int bs(vector<int> & nums, int target, int l, int r){
        int mid = l + (r-l)/2;
        if(l > r){
            return -1;
        }

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            return bs(nums, target, l, mid-1);
        }
        else if(nums[mid] < target){
            return bs(nums, target, mid+1, r);
        }
        else 
            return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};