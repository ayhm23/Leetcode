class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int currS = intervals[0][0];
        int currE = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            if(intervals[i][0] > currE){
                ans.push_back({currS, currE});
                currS = intervals[i][0];
                currE = intervals[i][1];
            }
            else{
                currE = max(currE, intervals[i][1]);
            }
        }

        ans.push_back({currS, currE});

        return ans;
    }
};