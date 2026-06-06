class Solution {
public:
    int div(vector<int>& nums, int d){
        int ans = 0;
        for(int x : nums){
            ans += (x + d - 1)/d;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int ans = hi;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int curr = div(nums, mid);

            if(curr <= threshold){
                ans = mid; hi = mid-1;
            }
            else lo = mid + 1;
        } 
        return ans;
    }
};