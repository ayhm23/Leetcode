class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int curr = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = curr;

        int left = k - 1, right = n - 1;

        while(left >= 0){
            curr = curr - cardPoints[left] + cardPoints[right];
            ans = max(ans, curr);
            left--; 
            right--;
        }

        return ans;
    }
};