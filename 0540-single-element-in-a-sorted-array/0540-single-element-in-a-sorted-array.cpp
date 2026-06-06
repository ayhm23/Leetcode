class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // single element found
            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]))
                return nums[mid];

            // paired with right
            if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                int len = hi - mid;   // elements from mid+1 to hi

                if (len % 2 == 0)
                    lo = mid + 2;
                else
                    hi = mid - 1;
            }

            // paired with left
            else {
                int len = mid - lo;   // elements from lo to mid-1

                if (len % 2 == 0)
                    hi = mid - 2;
                else
                    lo = mid + 1;
            }
        }

        return -1;
    }
};