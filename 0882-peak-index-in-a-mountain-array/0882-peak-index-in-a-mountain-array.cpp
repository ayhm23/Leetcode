class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low < high) { // No need for <=
            int mid = low + (high - low) / 2;
            
            // If we're still going uphill
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } 
            // If we're going downhill
            else {
                high = mid;
            }
        }
        
        return low; // low == high at the peak
    }
};
