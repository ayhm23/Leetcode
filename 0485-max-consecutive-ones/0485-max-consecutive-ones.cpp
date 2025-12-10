class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0, curr = 0;
        
        for(int i : nums){
            if(i == 1){
                curr++;
            } else {
                maxx = max(maxx, curr);
                curr = 0;
            }
        }
        
        return max(maxx, curr);
    }
};
