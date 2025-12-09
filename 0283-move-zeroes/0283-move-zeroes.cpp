class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int Zero = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                Zero = i;
                break;
            }
        }
        if(Zero == -1){
            return;
        }
        for(int i = Zero + 1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[Zero]);
                Zero++;
            }
        }
    }
};