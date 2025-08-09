class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        vector<int> ans = {-1, -1};
        int x = target;
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == x){
                ans[0] = mid;
                high = mid - 1;
            }

            if(nums[mid] < x){
                low = mid + 1;
            }
            else if(nums[mid] > x){
                high = mid - 1;
            }
        }
         low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == x){
                ans[1] = mid;
                low = mid + 1;
            }

            if(nums[mid] < x){
                low = mid + 1;
            }
            else if(nums[mid] > x){
                high = mid - 1;
            }
        }

        return ans;
    }
};