class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int write = 1;                 // next position to write a new unique value
        for (int read = 1; read < nums.size(); ++read) {
            if (nums[read] != nums[read - 1]) {   // new unique value found
                nums[write] = nums[read];         // place it at the write pointer
                ++write;
            }
        }
        return write;      // number of unique elements
    }
};
