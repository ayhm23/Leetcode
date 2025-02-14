class Solution {
public:

    //2 methods of solving...first is Dp

    

    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currentSum = 0;
        for(int num : nums){
            currentSum+=num;
            maxSum = max(currentSum,maxSum);

            if(currentSum < 0)currentSum = 0;

        }
        return maxSum;
    }
};