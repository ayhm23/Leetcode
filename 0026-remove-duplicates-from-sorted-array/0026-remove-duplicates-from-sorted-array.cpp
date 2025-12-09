class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, curr = nums[0];
        
        vector<int> temp(nums.size(), 0);
        temp[count-1] = curr;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != curr){
                curr = nums[i];
                count++;
                temp[count-1] = curr;
            }
        }
        nums = temp;
        return count;
    }
};