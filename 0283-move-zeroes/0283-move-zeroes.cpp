class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        int write = 0;
        for(int i  = 0; i < n; i++){
            if(nums[i] != 0){
                temp[write] = nums[i];
                write++;
            }   
        }
        nums = temp;
        return;

    }
};