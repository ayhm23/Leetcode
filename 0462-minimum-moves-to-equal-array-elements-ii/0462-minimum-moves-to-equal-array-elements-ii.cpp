class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int res = 0;
        int med;
        if(n % 2 == 0){
            //even
            med = (nums[n/2] + nums[(n+1)/2])/2;
        }
        else{
            //odd
            med = nums[n/2];
        }

        for(int i = 0; i < n; i++){
            res += abs(med - nums[i]);
        }
        
        return res;
    }
};