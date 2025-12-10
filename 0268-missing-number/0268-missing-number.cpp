class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*=n+1) / 2;
        int Asum = 0;
        for(int i : nums){
            Asum += i;
        }
        return sum - Asum;
    }
};