class Solution {
public:
    bool canEat(vector<int>& piles, int rate, int h){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += (piles[i] - 1)/rate + 1; // ceil
        }
        return hours <= h ? true : false;        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = hi;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(canEat(piles, mid, h)){
                ans = mid; hi = mid -1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};