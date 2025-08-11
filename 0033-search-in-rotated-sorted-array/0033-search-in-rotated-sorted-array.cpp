class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        //LEFT ROTATION OR RIGHT.. FINDING PIVOT IS SAME
        // Find pivot index
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int pivot = low;

        // Search in correct half
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return bs(nums, pivot, n - 1, target);
        } else {
            return bs(nums, 0, pivot - 1, target);
        }
    }
};
