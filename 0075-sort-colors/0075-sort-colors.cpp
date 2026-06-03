class Solution {
public:
    void sortColors(vector<int>& nums) {
        //3 pointer
        int lo = 0, mid = 0, hi = nums.size()-1;
        //make sure that all zeros are to left of mid and all 2s are to the right
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[lo++], nums[mid++]);
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[hi--], nums[mid]);
            }
        }
    }
};