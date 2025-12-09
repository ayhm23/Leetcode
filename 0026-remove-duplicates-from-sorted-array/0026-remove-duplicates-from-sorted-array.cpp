class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int write = 1;                // next index to write a unique element
        for (int read = 1; read < n; ++read) {
            if (nums[read] != nums[write - 1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};
