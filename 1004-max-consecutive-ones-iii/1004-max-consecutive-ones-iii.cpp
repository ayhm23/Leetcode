class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int buffer = 0, ans = 0, curr = 0;

        while(right < n){
            if(nums[right] == 1){
                curr++; right++;
            }
            else{ // is zerp
                if(buffer < k){
                    buffer++; right++; curr++;
                }
                else{
                    if(nums[left] != 0){
                        left++;
                        curr--;
                    }
                    else{
                        left++; right++;
                    }
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};