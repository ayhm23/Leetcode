class Solution {
public:
    long long getHours(vector<int>& piles, int n) {
        long long hours = 0;
        for (int i : piles) {
            hours += ceil((double)i/(double)n); // integer ceil division
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(getHours(piles, mid) <= h){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};