class Solution {
public:
    vector<int> Merge(vector<int>& a, vector<int>& b) {
        vector<int> c;
        int i = 0, j = 0;
        c.reserve(a.size() + b.size()); // Preallocate memory

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                c.push_back(a[i++]);
            } else {
                c.push_back(b[j++]);
            }
        }

        while (i < a.size()) {
            c.push_back(a[i++]);
        }
        while (j < b.size()) {
            c.push_back(b[j++]);
        }
        return c;
    }

    vector<int> MergeSort(vector<int>& nums, int left, int right) {
        if (left == right) {
            return {nums[left]};  // Wrap single element in a vector
        }

        int middle = left + (right - left) / 2;
        vector<int> leftSorted = MergeSort(nums, left, middle);
        vector<int> rightSorted = MergeSort(nums, middle + 1, right);

        return Merge(leftSorted, rightSorted);
    }

    vector<int> sortArray(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};
