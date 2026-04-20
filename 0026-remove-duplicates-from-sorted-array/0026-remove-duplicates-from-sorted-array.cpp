class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currInd = 1, currElem = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != currElem){
                nums[currInd] = nums[i];
                currInd++; currElem = nums[i];
            }
        }
        return currInd;
    }
};