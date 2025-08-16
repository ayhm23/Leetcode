class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int n){
        int tempSum = 0, count = 1;
        for(int i : nums){
            if(tempSum + i > n){
                count++;
                tempSum = i;
                if(count > k){
                    return false;
                }
            }
            else{
                tempSum+=i;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, k, mid)){
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