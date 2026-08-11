class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //care about the triplets that dont have the max greater than any element
        vector<int> curr = {INT_MIN, INT_MIN, INT_MIN};
        for(auto & it: triplets){
            if(it[0] <= target[0] && it[1] <= target[1] && it[2] <= target[2]){
                curr[0] = max(curr[0], it[0]);
                curr[1] = max(curr[1], it[1]);
                curr[2] = max(curr[2], it[2]);
            }
            if(curr == target) return true;
        }
        return false;
    }
};