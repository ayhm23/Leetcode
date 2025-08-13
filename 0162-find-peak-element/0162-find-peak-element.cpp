class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case: mid in between
            if (mid > 0 && mid < n - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    ans = mid;
                    break;
                }
                else if (nums[mid] < nums[mid + 1]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            // Case: mid == 0 (only check right neighbor to avoid overflow)
            else if (mid == 0) {
                if (n == 1 || nums[mid] > nums[mid + 1]) {
                    ans = mid;
                    break;
                }
                else {
                    low = mid + 1;
                }
            }
            // Case: mid == n-1 (only check left neighbor)
            else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    ans = mid;
                    break;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};
