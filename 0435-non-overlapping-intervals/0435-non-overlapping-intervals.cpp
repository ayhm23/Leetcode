class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b){
            return a[1] < b[1];
        });
        int currE = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            int st = intervals[i][0]; int en = intervals[i][1];

            if(st >= currE){
                currE = en;
                continue;
            }
            else{
                //overlap
                count++;
            }
        }
        return count;
    }
};