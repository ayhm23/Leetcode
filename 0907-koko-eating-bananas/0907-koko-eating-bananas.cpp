class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            long long hours = 0;
            for (int i : piles) {
                hours += ceil((double)i/(double)mid); // integer ceil division
            }
            if(hours <= h){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};