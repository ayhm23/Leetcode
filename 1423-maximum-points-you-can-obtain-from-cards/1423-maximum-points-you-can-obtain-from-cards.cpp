class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curr, maxx;
        curr = maxx = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);

        for(int i = 0; i < k; i++){
            curr = curr - cardPoints[k-1-i] + cardPoints[n-1-i];
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};