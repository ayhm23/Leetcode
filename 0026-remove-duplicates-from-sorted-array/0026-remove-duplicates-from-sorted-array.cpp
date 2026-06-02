class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int curr = 0;

        for(int next = 1; next < n; next++){
            if(nums[next] != nums[curr]){
                nums[++curr] = nums[next];
            }
        } 
        return curr+1;
    }
};