class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxx = 0;
        for(int x : st){
            if(!st.count(x-1)){
                //start
                int curr = x, len = 1;
                while(st.count(++curr)) len++;
                maxx = max(maxx, len);
            }
        }
        return maxx;
    }
};