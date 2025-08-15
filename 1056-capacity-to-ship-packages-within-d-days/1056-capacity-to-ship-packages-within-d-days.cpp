class Solution {
public:
    int countDays(vector<int>& nums, int capacity) {
        int count = 1; // at least 1 day
        int tempsum = 0;
        for (int w : nums) {
            if (tempsum + w > capacity) {
                count++;
                tempsum = 0;
            }
            tempsum += w;
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int req = countDays(weights, mid);

            if (req <= days) {
                ans = mid;
                high = mid - 1; // try smaller capacity
            } else {
                low = mid + 1; // need bigger capacity
            }
        }
        return ans;
    }
};