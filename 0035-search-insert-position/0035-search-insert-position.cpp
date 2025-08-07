class Solution {
public:
    int bs(vector<int> &nums, int target, int l, int r) {
        if (l > r) return l; // insert position

        int mid = l + (r - l) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target)
            return bs(nums, target, l, mid - 1);
        else
            return bs(nums, target, mid + 1, r);
    }

    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);   
    }
};
