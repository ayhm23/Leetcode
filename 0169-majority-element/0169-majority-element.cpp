class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //approach 1 : BF : iterate through array and count occurance with nester loop - O(n^2) O(1)
        //approach 2 : hashmap : count eash occurance..itereate through hashmap to find the highest occuring element = O(N) O(N)
        //approach 3 : make use of the always exisiting statement..keep counter.. if counter zero.. count new element..

        int count = 1 , element = nums[0];
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] == element){
                count++;
            }
            else{
                if(count == 0){
                    count = 1;
                    element = nums[i];
                }
                else{
                    count--;
                }
            }
        }
        return element;
    }
};