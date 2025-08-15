class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int k, int n){
        int i = 0;
        int count = 0, adjacent = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= n){
                adjacent++;
                if(adjacent == k){
                    count++;
                    adjacent = 0;
                    continue;
                }
            }
            else{
                adjacent = 0;
            }
        }
        return (count >= m ? true : false);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(bloomDay, m, k, mid)){
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