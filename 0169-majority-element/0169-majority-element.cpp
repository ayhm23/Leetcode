#include <vector>
using namespace std;

class Solution {
public:
    // Function to count occurrences of 'num' in the subarray [left, right]
    int countOccurrences(vector<int>& nums, int left, int right, int num) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    int majorElement(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        // Corrected midpoint calculation
        int mid = left + (right - left) / 2;

        // Recursively find majority elements in left and right halves
        int leftMajor = majorElement(nums, left, mid);
        int rightMajor = majorElement(nums, mid + 1, right);

        // If both halves agree on the majority element, return it
        if (leftMajor == rightMajor) {
            return leftMajor;
        }

        // Count occurrences in the current range
        int leftCount = countOccurrences(nums, left, right, leftMajor);
        int rightCount = countOccurrences(nums, left, right, rightMajor);

        return (leftCount > rightCount) ? leftMajor : rightMajor;
    }

    int majorityElement(vector<int>& nums) {
        return majorElement(nums, 0, nums.size() - 1);
    }
};
