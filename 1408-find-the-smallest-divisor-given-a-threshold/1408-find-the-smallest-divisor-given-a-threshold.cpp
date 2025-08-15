class Solution {
public:
    int DivSum(vector<int>&nums, int n){
        int ans = 0;
        for(int i : nums){
            int a = ceil((double)i/(double)n);
            ans += (a == 0 ? 1 : a);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            int tempSum = DivSum(nums, mid);

            if(tempSum <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};