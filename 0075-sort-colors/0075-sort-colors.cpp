class Solution {
public:
    void sortColors(vector<int>& nums) {
        //a1 : count all 0s 1s 2s and give array accordnigly
        //a2 : left right and read pointer
        //Dutch flag colour algorithm

        int n = nums.size();
        int left = 0; int right = n-1;
        int reader = 0;
        //left >=  reader and right <= reader
        while(reader <= right){
            if(nums[reader] == 0){
                swap(nums[left], nums[reader]);
                left++; reader++;
            }
            else if(nums[reader] == 1){
                reader++;
            }
            else if(nums[reader] == 2){
                swap(nums[right], nums[reader]);
                right--;
            }
        }
    }
};