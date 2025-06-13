class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                sum+=1;
                continue;
            }
            else{
                maxx = max(sum, maxx);
                sum = 0;
                continue;
            }
        }

        return max(sum, maxx);
    }
};